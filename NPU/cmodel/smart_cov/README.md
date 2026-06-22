# smart_cov - Multi-language Code Coverage Testing Tool

A powerful, flexible code coverage tool that supports Python, C/C++ and Java, with unified configuration and report generation. It can be easily deployed as a standalone folder into any project.

## 🎯 Features

- **Multi-language Support**: Full support for Python, C/C++ and Java
- **Unified Configuration**: Single YAML config file for all languages
- **Local Project Integration**: Can be deployed as a standalone folder into any existing project for coverage checking
- **Comprehensive Reports**: Generates clear HTML coverage reports
- **Windows/Linux Compatibility**: Works on both operating systems
- **User-friendly CLI**: Simple command-line interface with help documentation
- **Auto-configuration**: Detects project languages and sets up coverage tools automatically
- **Multi-config Format Support**: Works with both old and new configuration formats

## 📋 Supported Languages

| Language | Status       | Coverage Tool |
|----------|--------------|---------------|
| Python   | ✅ Enabled   | coverage.py   |
| C/C++    | ✅ Enabled   | GCOV + LCOV   |
| Java     | ✅ Enabled   | JaCoCo + Maven |

## 📝 Configuration

Configuration is stored in `config/config.yml` and follows this structure:

```yaml
project:
  name: smart_cov_demo
  description: Multi-language code coverage testing tool demo project
  version: 1.0

language.python:
  enabled: true
  project_path: examples/python
  test_command: python -m coverage run -m pytest tests/ -v
  coverage_tool: coverage.py
  report_type: html
  report_dir: coverage_reports/python
  source_paths: ["src"]
  test_paths: ["tests"]
  ignore_paths: ["venv/", "__pycache__/"]

language.c_cpp:
  enabled: true
  project_path: examples/c_cpp
  test_command: test_calculator.exe
  build_command: build.bat
  clean_command: del /Q test_calculator.exe *.gcda *.gcno coverage.info 2>nul
  coverage_tool: gcov+lcov+genhtml
  report_type: html
  report_dir: coverage_reports/c_cpp
  source_paths: ["src"]
  test_paths: ["tests"]
  ignore_paths: ["build/", "bin/", "obj/"]

language.java:
  enabled: true
  project_path: examples/java
  test_command: mvn test jacoco:report
  build_command: mvn compile
  clean_command: mvn clean
  coverage_tool: jacoco+maven
  report_type: html
  report_dir: coverage_reports/java
  source_paths: ["src/main/java"]
  test_paths: ["src/test/java"]
  ignore_paths: ["target/"]

# Local project coverage configuration (for any external project)
local:
  enabled: true
  python_enabled: true
  c_cpp_enabled: false
  java_enabled: false
  project_path: "D:\\workspace\\tvm"  # Path to your external project
  python_test_command: python -m coverage run -m pytest tests/ -v
  coverage_tool: coverage.py
  c_cpp_test_command: test_calculator.exe
  c_cpp_build_command: build.bat
  c_cpp_clean_command: del /Q test_calculator.exe *.gcda *.gcno coverage.info 2>nul
  c_cpp_coverage_tool: gcov+lcov+genhtml
  java_test_command: mvn test jacoco:report
  java_build_command: mvn compile
  java_coverage_tool: jacoco+maven
  report_type: html
  report_dir: coverage_reports/local
  source_paths: ["src"]
  test_paths: ["tests"]
  ignore_paths: ["venv/", "__pycache__/", "build/", "coverage_reports/"]

global:
  clean_before_run: true
  verbose: true
  ignore_paths: [".git/", ".log", "temp/"]
```

## 🚀 Usage

### Prerequisites

- **Python**: Python 3.x and `coverage.py` (install via pip)
- **C/C++**: GCC compiler, make, gcov, lcov and genhtml (install via MinGW on Windows)
- **Java**: JDK 8+ and Maven

### Installation

1. **Deploy to target project**: Copy the entire `smart_cov` folder into your target project's root directory
2. **Install dependencies**: Run `pip install -r requirements.txt`
3. **Configure for target project**: Edit `config/config.yml` to match your project structure and languages

### Command Examples

1. **Run coverage tests for all enabled languages**: 
```bash
cd your_project/smart_cov
python smart_cov.py
```

2. **Run coverage tests for a specific language or local project**: 
```bash
# Run Python coverage only
python smart_cov.py -l python

# Run C/C++ coverage only
python smart_cov.py -l c_cpp

# Run Java coverage only
python smart_cov.py -l java

# Run coverage on a local external project (configured in config.yml)
python smart_cov.py -l local
```

3. **Use custom configuration file**: 
```bash
python smart_cov.py --config path/to/custom_config.yml
```

## 📊 Reports

Coverage reports are centralized in the `coverage_reports/` directory within the `smart_cov` folder:

- **Python**: `coverage_reports/python/index.html`
- **C/C++**: `coverage_reports/c_cpp/index.html`
- **Java**: `coverage_reports/java/index.html`
- **Local External Project**: `coverage_reports/local/index.html`

Open these files in a web browser to view detailed coverage information.

## 📂 Project Structure

```
your_target_project/
├── ... existing files and directories ...
└── smart_cov/              # Deployed as a standalone folder
    ├── config/
    │   └── config.yml      # Main configuration file
    ├── examples/           # Example projects for reference
    │   ├── python/         # Python sample
    │   ├── c_cpp/          # C/C++ sample
    │   └── java/           # Java sample
    ├── coverage_reports/   # Generated coverage reports for all projects
    ├── smart_cov.py        # Main tool script
    ├── requirements.txt    # Python dependencies
    └── README.md           # This file
```

## 🛠️ Development & Contribution

- The project is written in pure Python 3 with minimal third-party dependencies
- Contributions for bug fixes, new features and language support are welcome
- Please ensure all code and documentation are clear and consistent

## 📄 License

MIT License - Feel free to use this tool for your projects.

