# Get the scan insertion settings
source -e -v scripts/settings_insert_dft.tcl

# Specify the autofix configuration
source -e -v scripts/autofix.tcl

# Preview the scan architecture / test points
preview_dft; # Lets you know what you will get -- iterate from here - 
