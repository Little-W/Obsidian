# Set a prefix to identify cells added by insert_dft
set compile_instance_name_prefix DFTC_

# Insert the scan architecture
insert_dft

# Run Post-DFT DRC check and get a coveage estimate from TetraMAX
dft_drc -coverage_estimate

