source -echo -ver scripts/settings_insert_dft.tcl 
remove_test_protocol
create_test_protocol
dft_drc
preview_dft -show scan_summary
