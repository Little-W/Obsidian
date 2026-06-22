#!/usr/bin/env python3
"""
Universal Coverage Analysis Script (Supports 4 C/C++ Compilers + Python)
Final Fix: Parse coverage.info file directly to get accurate coverage values
"""

import os
import sys
import subprocess
import re
from datetime import datetime
from typing import List, Dict, Tuple, Optional

import yaml
import argparse


class CoverageChecker:
    """
    Coverage Checker Class (Supports 4 C/C++ Compilers + Python)
    """
    def __init__(self, config_path: Optional[str] = None):
        # Basic path configuration
        self.tool_root = os.path.dirname(os.path.abspath(__file__))
        self.project_root = os.path.abspath(os.path.join(self.tool_root, ".."))
        self.config_path = config_path or self._find_config()
        self.config = self._load_config()
        
        # C/C++ core variables
        self.coverage_data_dir = self._get_coverage_data_dir()
        self.compiler_type: Optional[str] = None  # C/C++ compiler type
        self.compiler: Optional[str] = None       # C/C++ compiler path
        self.cov_tool: Optional[str] = None       # C/C++ coverage tool
        # Store raw coverage data parsed from coverage.info
        self.c_cpp_coverage_data = {
            "line": 0.0,
            "function": 0.0,
            "branch": -1.0  # -1 means no data
        }

    def _find_config(self) -> str:
        """Find configuration file in predefined paths"""
        config_paths = [
            os.path.join(self.tool_root, "config", "config.yml"),
            os.path.join(self.project_root, "config.yml"),
        ]
        for path in config_paths:
            if os.path.exists(path):
                print(f"✅ Loading config file: {path}")
                return path
        raise FileNotFoundError("❌ Config file not found. Please check smart_cov/config/config.yml")

    def _load_config(self) -> Dict:
        """Load YAML configuration file"""
        try:
            with open(self.config_path, "r", encoding="utf-8") as config_file:
                return yaml.safe_load(config_file)
        except yaml.YAMLError as yaml_err:
            raise RuntimeError(f"❌ Failed to parse config file: {str(yaml_err)}") from yaml_err
        except Exception as general_err:
            raise RuntimeError(f"❌ Failed to load config file: {str(general_err)}") from general_err

    def _get_coverage_data_dir(self) -> str:
        """Get absolute path for C/C++ coverage data directory"""
        c_cpp_cfg = self.config.get("language", {}).get("c_cpp", {})
        cov_data_dir_rel = c_cpp_cfg.get("coverage_data_dir", "./coverage_data")
        cov_data_dir_abs = os.path.abspath(os.path.join(self.tool_root, cov_data_dir_rel))
        os.makedirs(cov_data_dir_abs, exist_ok=True)
        print(f"✅ C/C++ coverage data directory: {cov_data_dir_abs}")
        return cov_data_dir_abs

    def _find_executable_in_paths(self, paths: List[str]) -> Optional[str]:
        """
        Find valid executable from multiple paths
        Returns first valid executable path, None if none found
        """
        for path in paths:
            # For system commands (like g++/clang++), check if executable
            if not os.path.isabs(path):
                try:
                    subprocess.run([path, "--version"], capture_output=True, check=False)
                    return path
                except (subprocess.CalledProcessError, FileNotFoundError, PermissionError):
                    continue
            # For absolute paths, check file existence and executable permission
            else:
                if os.path.exists(path) and os.access(path, os.X_OK):
                    return path
        return None

    def _identify_compiler_type(self, compiler_path: str) -> str:
        """Identify compiler type from path/version info"""
        # Check for RISC-V compilers first
        if any(path in compiler_path for path in ["/workspace/nuclei/gcc/bin", "/data/nuclei/gcc/bin"]):
            if "clang++" in compiler_path:
                return "riscv_clang"
            elif "g++" in compiler_path:
                return "riscv_gcc"
        
        # Check for system compilers
        try:
            result = subprocess.run(
                [compiler_path, "--version"], capture_output=True, text=True, check=False
            )
            if "clang" in result.stdout.lower() or "llvm" in result.stdout.lower():
                return "system_clang"
            elif "gcc" in result.stdout.lower() or "gnu" in result.stdout.lower():
                return "system_gcc"
        except Exception:
            # Fallback to path-based detection
            if "clang++" in compiler_path:
                return "system_clang"
        
        # Default to system_gcc
        return "system_gcc"

    def _get_compiler(self) -> None:
        """
        Get valid C/C++ compiler from configuration
        Supports multiple paths for cross-compilers
        """
        c_cpp_cfg = self.config.get("language", {}).get("c_cpp", {})
        compiler_type = c_cpp_cfg.get("compiler_type", "auto")
        compiler_mapping = c_cpp_cfg.get("compiler_mapping", {})
        
        # 1. Explicit compiler type (highest priority)
        if compiler_type in compiler_mapping:
            compiler_paths = compiler_mapping[compiler_type]
            # Ensure it's a list even if single path in config
            compiler_paths = [compiler_paths] if not isinstance(compiler_paths, list) else compiler_paths
            
            self.compiler = self._find_executable_in_paths(compiler_paths)
            if self.compiler:
                self.compiler_type = compiler_type
                print(f"✅ Using {compiler_type.upper()} compiler: {self.compiler}")
                return
            else:
                raise RuntimeError(f"❌ No valid {compiler_type} compiler found in paths: {compiler_paths}")
        
        # 2. Auto mode: find first available compiler
        print("🔍 Auto mode: Scanning available compilers...")
        for comp_type, comp_paths in compiler_mapping.items():
            comp_paths = [comp_paths] if not isinstance(comp_paths, list) else comp_paths
            valid_compiler = self._find_executable_in_paths(comp_paths)
            
            if valid_compiler:
                self.compiler_type = comp_type
                self.compiler = valid_compiler
                print(f"✅ Auto found {comp_type.upper()} compiler: {valid_compiler}")
                return
        
        # 3. Auto mode failed
        raise RuntimeError("❌ Auto mode failed to find any valid C/C++ compiler. Check compiler_mapping config.")

    def _get_cov_tool(self) -> None:
        """
        Get valid coverage tool for selected compiler
        Supports multiple paths for cross-compiler tools
        """
        if not self.compiler_type:
            raise RuntimeError("❌ Compiler type not set. Call _get_compiler() first.")
        
        c_cpp_cfg = self.config.get("language", {}).get("c_cpp", {})
        cov_tool_mapping = c_cpp_cfg.get("cov_tool_mapping", {})
        
        # Get all possible paths for current compiler type
        cov_tool_paths = cov_tool_mapping.get(self.compiler_type, [])
        cov_tool_paths = [cov_tool_paths] if not isinstance(cov_tool_paths, list) else cov_tool_paths
        
        # Find valid coverage tool
        for tool_path in cov_tool_paths:
            # Split tool path and arguments (e.g., "llvm-cov gcov")
            tool_parts = tool_path.split(" ")
            tool_exec = tool_parts[0]
            
            # Check if tool executable exists
            if self._find_executable_in_paths([tool_exec]):
                self.cov_tool = tool_path
                print(f"✅ Found {self.compiler_type.upper()} coverage tool: {self.cov_tool}")
                return
        
        raise RuntimeError(f"❌ No valid coverage tool found for {self.compiler_type} in paths: {cov_tool_paths}")

    def _exec_cmd(self, cmd: str, cwd: Optional[str] = None) -> Tuple[bool, str]:
        """
        Execute system command and return (success, output)
        Args:
            cmd: Command to execute
            cwd: Working directory (default: project root)
        Returns:
            Tuple of (success flag, command output)
        """
        work_dir = cwd or self.project_root
        print(f"\n[Executing command] {cmd}")
        
        try:
            result = subprocess.run(
                cmd, shell=True, cwd=work_dir, capture_output=True, text=True, check=True,
                executable="/bin/bash"
            )
            output = result.stdout + "\n" + result.stderr
            
            if result.stdout:
                print(f"[Standard Output]\n{result.stdout}")
            if result.stderr:
                print(f"[Standard Error]\n{result.stderr}")
            
            return True, output
        except subprocess.CalledProcessError as cmd_err:
            print(f"❌ Command execution failed: {str(cmd_err)}")
            print(f"Error output: {cmd_err.stderr}")
            return False, cmd_err.stderr

    def _find_cov_files(self, ext: str) -> List[str]:
        """Find coverage files (.gcda/.gcno) in predefined directories"""
        files = []
        # First scan coverage data directory
        for root, _, filenames in os.walk(self.coverage_data_dir):
            for fname in filenames:
                if fname.endswith(ext):
                    files.append(os.path.join(root, fname))
        
        # Fallback to project root if no files found
        if not files:
            print(f"⚠️ No {ext} files found in coverage data dir {self.coverage_data_dir}, scanning project root")
            ignore_paths = self.config.get("global", {}).get("ignore_paths", [])
            
            for root, _, filenames in os.walk(self.project_root):
                if any(ignored in root for ignored in ignore_paths):
                    continue
                for fname in filenames:
                    if fname.endswith(ext):
                        files.append(os.path.join(root, fname))
        
        return files

    def _parse_c_cpp_coverage_from_info_file(self) -> None:
        """
        Parse accurate coverage data (including branch coverage) from coverage.info
        This is the core fix for accurate coverage calculation
        """
        # Try multiple possible info file paths
        info_file_paths = [
            os.path.join(self.project_root, "coverage.info"),
            os.path.join(self.project_root, "coverage_raw.info")
        ]
        info_file = None
        
        for path in info_file_paths:
            if os.path.exists(path):
                info_file = path
                break
        
        if not info_file:
            raise FileNotFoundError(f"❌ Coverage info file not found in paths: {info_file_paths}")
        
        # Initialize statistics
        total_lines = 0
        covered_lines = 0
        total_functions = 0
        covered_functions = 0
        total_branches = 0
        covered_branches = 0
        
        # Parse coverage info file line by line
        with open(info_file, "r", encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                # Parse line coverage (DA:line_number,execution_count)
                if line.startswith("DA:"):
                    total_lines += 1
                    parts = line.split(":")[1].split(",")
                    if len(parts) >= 2 and parts[1].isdigit() and int(parts[1]) > 0:
                        covered_lines += 1
                # Parse function coverage (FNDA:execution_count,function_name)
                elif line.startswith("FNDA:"):
                    total_functions += 1
                    parts = line.split(":")[1].split(",")
                    if len(parts) >= 2 and parts[0].isdigit() and int(parts[0]) > 0:
                        covered_functions += 1
                # Parse branch coverage (BRDA:line,branch,covered,count)
                elif line.startswith("BRDA:"):
                    total_branches += 1
                    parts = line.split(":")[1].split(",")
                    # BRDA format: line, branch_num, is_covered(0/1), count
                    if len(parts) >= 3:
                        if (parts[2] == "1") or (len(parts)>=4 and parts[3].isdigit() and int(parts[3])>0):
                            covered_branches += 1
        
        # Calculate coverage percentages (avoid division by zero)
        self.c_cpp_coverage_data["line"] = round((covered_lines / total_lines * 100), 1) if total_lines > 0 else 0.0
        self.c_cpp_coverage_data["function"] = round((covered_functions / total_functions * 100), 1) if total_functions > 0 else 0.0
        self.c_cpp_coverage_data["branch"] = round((covered_branches / total_branches * 100), 1) if total_branches > 0 else -1.0
        
        # Print parsed data for verification
        print(f"\n📊 Raw coverage data parsed from {info_file}:")
        print(f"   Total lines: {total_lines} | Covered lines: {covered_lines} | Line coverage: {self.c_cpp_coverage_data['line']}%")
        print(f"   Total functions: {total_functions} | Covered functions: {covered_functions} | Function coverage: {self.c_cpp_coverage_data['function']}%")
        print(f"   Total branches: {total_branches} | Covered branches: {covered_branches} | Branch coverage: {self.c_cpp_coverage_data['branch']}%")

    def _check_c_cpp_threshold(self) -> bool:
        """Check if C/C++ coverage meets configured thresholds"""
        c_cpp_cfg = self.config.get("language", {}).get("c_cpp", {})
        thresholds = c_cpp_cfg.get("thresholds", {})
        
        print("\n=== C/C++ Coverage Threshold Check ===")
        # Format coverage values for output
        line_cov = f"{self.c_cpp_coverage_data['line']}%"
        func_cov = f"{self.c_cpp_coverage_data['function']}%"
        branch_cov = "No data" if self.c_cpp_coverage_data['branch'] == -1.0 else f"{self.c_cpp_coverage_data['branch']}%"
        
        print(f"Current coverage: Line={line_cov} | Branch={branch_cov} | Function={func_cov}")
        print(f"Required thresholds: Line={thresholds.get('line', 0)}% | Branch={thresholds.get('branch', 0)}% | Function={thresholds.get('function', 0)}%")
        
        passed = True
        # Check line coverage
        if self.c_cpp_coverage_data["line"] < thresholds.get("line", 0):
            print(f"❌ C/C++ line coverage {line_cov} is below threshold {thresholds['line']}%")
            passed = False
        else:
            print(f"✅ C/C++ line coverage {line_cov} meets threshold")
        
        # Check function coverage
        if self.c_cpp_coverage_data["function"] < thresholds.get("function", 0):
            print(f"❌ C/C++ function coverage {func_cov} is below threshold {thresholds['function']}%")
            passed = False
        else:
            print(f"✅ C/C++ function coverage {func_cov} meets threshold")
        
        # Check branch coverage
        if self.c_cpp_coverage_data["branch"] == -1.0:
            print(f"⚠️ No C/C++ branch coverage data (add -fbranch-probabilities to compiler flags)")
        elif self.c_cpp_coverage_data["branch"] < thresholds.get("branch", 0):
            print(f"❌ C/C++ branch coverage {branch_cov} is below threshold {thresholds['branch']}%")
            passed = False
        else:
            print(f"✅ C/C++ branch coverage {branch_cov} meets threshold")
        
        # Fail fast if configured
        if not passed and self.config.get("global", {}).get("fail_on_threshold", True):
            raise RuntimeError("❌ C/C++ coverage did not meet thresholds. Process terminated.")
        
        return passed

    def run_c_cpp_coverage(self) -> bool:
        """Execute C/C++ coverage analysis (final fixed version)"""
        c_cpp_cfg = self.config.get("language", {}).get("c_cpp", {})
        if not c_cpp_cfg.get("enabled", False):
            print("=== C/C++ coverage analysis is disabled ===")
            return True

        print("\n=== Starting C/C++ Coverage Analysis ===")
        # Initialize compiler and coverage tool
        self._get_compiler()
        self._get_cov_tool()

        # Prepare report directory
        report_dir = os.path.join(self.tool_root, c_cpp_cfg.get("report_dir", "coverage_reports/c_cpp"))
        os.makedirs(report_dir, exist_ok=True)

        # Check for required coverage files
        gcda_files = self._find_cov_files(".gcda")
        gcno_files = self._find_cov_files(".gcno")
        
        if not gcda_files or not gcno_files:
            raise RuntimeError(f"❌ C/C++ coverage data files (.gcda/.gcno) not found. Check {self.coverage_data_dir}")
        
        print(f"✅ Found {len(gcda_files)} .gcda files and {len(gcno_files)} .gcno files")

        # Generate raw coverage.info with branch coverage enabled
        gcov_tool_escaped = self.cov_tool.replace(" ", "\\ ") if " " in self.cov_tool else self.cov_tool
        lcov_base_cmd = (
            f"lcov --gcov-tool {gcov_tool_escaped} "
            f"-c -b {self.project_root} "
            f"-d {self.coverage_data_dir} "
            f"-o {self.project_root}/coverage_raw.info "
            f"--no-external "
            f"--ignore-errors unused,gcov,source "
            f"--rc lcov_branch_coverage=1 "
            f"--rc geninfo_branch_coverage=1"
        )
        
        success, _ = self._exec_cmd(lcov_base_cmd)
        if not success:
            # Fallback: minimal command with core branch coverage parameters
            print("⚠️ Standard lcov command failed, trying fallback (core parameters only)")
            lcov_base_cmd = (
                f"lcov --gcov-tool {gcov_tool_escaped} "
                f"-c -b {self.project_root} "
                f"-d {self.coverage_data_dir} "
                f"-o {self.project_root}/coverage_raw.info "
                f"--rc lcov_branch_coverage=1"
            )
            success, _ = self._exec_cmd(lcov_base_cmd)
            if not success:
                raise RuntimeError("❌ Failed to generate raw C/C++ coverage info (including fallback)")

        # Filter ignore paths (preserve branch coverage data)
        lcov_remove_cmd = f"lcov -o {self.project_root}/coverage.info --remove {self.project_root}/coverage_raw.info"
        for path in c_cpp_cfg.get("ignore_paths", []):
            abs_ignore_path = os.path.abspath(os.path.join(self.project_root, path))
            lcov_remove_cmd += f" '{abs_ignore_path}/*'"
        lcov_remove_cmd += f" --rc lcov_branch_coverage=1"
        
        success, _ = self._exec_cmd(lcov_remove_cmd)
        if not success:
            print("⚠️ Failed to remove ignore paths, using raw coverage info")
            self._exec_cmd(f"cp {self.project_root}/coverage_raw.info {self.project_root}/coverage.info")

        # Generate HTML report with branch coverage
        genhtml_cmd = (
            f"genhtml {self.project_root}/coverage.info "
            f"-o {report_dir} "
            f"--legend --show-details "
            f"--branch-coverage "
            f"--rc lcov_branch_coverage=1"
        )
        
        success, _ = self._exec_cmd(genhtml_cmd)
        if not success:
            print("⚠️ Standard genhtml command failed, trying fallback")
            genhtml_cmd = f"genhtml {self.project_root}/coverage.info -o {report_dir} --branch-coverage"
            success, _ = self._exec_cmd(genhtml_cmd)
            if not success:
                raise RuntimeError("❌ Failed to generate C/C++ HTML report (including fallback)")
        
        print(f"✅ C/C++ HTML report generated: {report_dir}/index.html")

        # Parse coverage data from info file (core fix)
        self._parse_c_cpp_coverage_from_info_file()

        # Check coverage thresholds
        self._check_c_cpp_threshold()
        return True

    # ===================== Python Coverage Analysis (Unmodified Logic) =====================
    def _parse_python_coverage_report(self, report_dir: str) -> Dict[str, float]:
        """Parse Python coverage percentage from HTML report"""
        cov_report_file = os.path.join(report_dir, "index.html")
        if not os.path.exists(cov_report_file):
            raise FileNotFoundError(f"❌ Python coverage report not generated: {cov_report_file}")
        
        with open(cov_report_file, "r", encoding="utf-8") as f:
            content = f.read()
        
        line_match = re.search(r"<span class=\"pc_cov\">(\d+\.\d+)%<\/span>", content)
        if not line_match:
            line_match = re.search(r"Coverage summary for.*?: (\d+\.\d+)%", content)
        
        cov_data = {}
        cov_data["line"] = float(line_match.group(1)) if line_match else 0.0
        return cov_data

    def _check_python_threshold(self, report_dir: str) -> bool:
        """Check if Python coverage meets configured thresholds"""
        python_cfg = self.config.get("language", {}).get("python", {})
        thresholds = python_cfg.get("thresholds", {})
        cov_data = self._parse_python_coverage_report(report_dir)
        
        print("\n=== Python Coverage Threshold Check ===")
        print(f"Current coverage: Line={cov_data['line']}%")
        print(f"Required threshold: Line={thresholds.get('line', 0)}%")
        
        passed = True
        if cov_data["line"] < thresholds.get("line", 0):
            print(f"❌ Python line coverage {cov_data['line']}% is below threshold {thresholds['line']}%")
            passed = False
        else:
            print(f"✅ Python line coverage {cov_data['line']}% meets threshold")
        
        if not passed and self.config.get("global", {}).get("fail_on_threshold", True):
            raise RuntimeError("❌ Python coverage did not meet thresholds. Process terminated.")
        
        return passed

    def run_python_coverage(self) -> bool:
        """Execute Python coverage analysis"""
        python_cfg = self.config.get("language", {}).get("python", {})
        if not python_cfg.get("enabled", False):
            print("=== Python coverage analysis is disabled ===")
            return True

        print("\n=== Starting Python Coverage Analysis ===")
        report_dir = os.path.join(self.tool_root, python_cfg.get("report_dir", "coverage_reports/python"))
        os.makedirs(report_dir, exist_ok=True)

        # Clean old coverage data
        self._exec_cmd("rm -rf .coverage*", cwd=self.project_root)
        print("✅ Cleaned old Python coverage data")

        # Run tests with coverage collection
        test_command = python_cfg.get("test_command", "")
        if not test_command:
            raise RuntimeError("❌ Python test command not configured")
        
        success, _ = self._exec_cmd(test_command, cwd=self.project_root)
        if not success:
            raise RuntimeError("❌ Failed to execute Python test command. Check test_command config.")
        
        print("✅ Python tests completed, .coverage data file generated")

        # Generate HTML report
        source_paths = python_cfg.get("source_paths", [])
        coverage_report_cmd = f"python3 -m coverage html -d {report_dir}"
        
        if source_paths:
            coverage_report_cmd += " --include=" + ",".join(source_paths)
        
        success, _ = self._exec_cmd(coverage_report_cmd, cwd=self.project_root)
        if not success:
            raise RuntimeError("❌ Failed to generate Python HTML report")
        
        print(f"✅ Python HTML report generated: {report_dir}/index.html")

        # Print console summary
        self._exec_cmd("python3 -m coverage report --show-missing", cwd=self.project_root)

        # Check coverage thresholds
        self._check_python_threshold(report_dir)
        return True

    # ===================== Main Execution Flow =====================
    def run(self) -> bool:
        """Main execution flow for coverage analysis"""
        print(f"=== Starting Coverage Analysis {datetime.now().strftime('%Y-%m-%d %H:%M:%S')} ===")
        print(f"Tool root directory: {self.tool_root}")
        print(f"Project root directory: {self.project_root}")

        try:
            # Run C/C++ coverage analysis if enabled
            if self.config.get("language", {}).get("c_cpp", {}).get("enabled", False):
                self.run_c_cpp_coverage()
            
            # Run Python coverage analysis if enabled
            if self.config.get("language", {}).get("python", {}).get("enabled", False):
                self.run_python_coverage()

            print("\n✅ All coverage analysis completed successfully!")
            print(f"📊 C/C++ Report Path: {self.tool_root}/coverage_reports/c_cpp/index.html")
            print(f"📊 Python Report Path (if enabled): {self.tool_root}/coverage_reports/python/index.html")
            return True
        
        except RuntimeError as runtime_err:
            print(f"\n❌ Coverage analysis failed: {str(runtime_err)}")
            sys.exit(1)


def main():
    """Script main entry point"""
    parser = argparse.ArgumentParser(description="Universal Coverage Analysis Tool (Final Fix: Parse coverage.info directly)")
    parser.add_argument("--config", type=str, help="Custom config file path")
    parser.add_argument("--compiler", type=str, help="Manually specify C/C++ compiler path")
    args = parser.parse_args()
    
    # Initialize coverage checker
    checker = CoverageChecker(config_path=args.config)
    
    # Override compiler if manually specified
    if args.compiler:
        checker.compiler = args.compiler
        checker.compiler_type = checker._identify_compiler_type(args.compiler)
        checker._get_cov_tool()
    
    # Run coverage analysis
    checker.run()


if __name__ == "__main__":
    main()
