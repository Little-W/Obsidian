# Set a variable to identify logic added by insert_dft
set compile_instance_name_prefix DFTC_

# Insert scan logic
insert_dft

# Run post-DFT DRC check and get a coverage estimate
dft_drc -coverage_estimate
