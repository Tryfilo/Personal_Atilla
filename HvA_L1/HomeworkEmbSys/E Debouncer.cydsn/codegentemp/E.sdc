# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\atill\OneDrive\Documenten\PSoC Creator\Homework\E.cydsn\E.cyprj
# Date: Mon, 04 Jan 2021 17:03:17 GMT
#set_units -time ns
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {ADC_SAR_1_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 17 35} -nominal_period 708.33333333333326 [list [get_pins {ClockBlock/aclk_glb_0}]]


# Component constraints for C:\Users\atill\OneDrive\Documenten\PSoC Creator\Homework\E.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\atill\OneDrive\Documenten\PSoC Creator\Homework\E.cydsn\E.cyprj
# Date: Mon, 04 Jan 2021 17:03:12 GMT
