// ======================================================================
// Design01_Copy_02.v generated from TopDesign.cysch
// 01/04/2021 at 15:22
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC5LP 2
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 3
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_TMA4 4
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 5
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC6ABLE2 6
`define CYDEV_CHIP_REV_PSOC6ABLE2_ES 17
`define CYDEV_CHIP_REV_PSOC6ABLE2_PRODUCTION 33
`define CYDEV_CHIP_REV_PSOC6ABLE2_NO_UDB 33
`define CYDEV_CHIP_DIE_VOLANS 7
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 8
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 9
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 10
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 11
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 2
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 2
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AC 14
`define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AD 15
`define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AE 16
`define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 17
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 18
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Z 19
`define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 20
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 21
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 22
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 23
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 24
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AA 25
`define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 26
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 27
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 28
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 29
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AB 30
`define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 31
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 32
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 33
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 37
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 38
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 2
`define CYDEV_CHIP_REVISION_USED 0
// top
module top ;

    electrical  Net_73;
    electrical  Net_70;
    electrical  Net_67;
    electrical  Net_64;
    electrical  Net_62;
    electrical  Net_61;
    electrical  Net_58;
    electrical  Net_56;
    electrical  Net_54;
    electrical  Net_52;
    electrical  Net_48;
    electrical  Net_51;
    electrical  Net_50;
    electrical  Net_43;
    electrical  Net_38;
    electrical  Net_74;
    electrical  Net_68;
    electrical  Net_71;
    electrical  Net_65;
    electrical  Net_63;
    electrical  Net_69;
    electrical  Net_72;
    electrical  Net_60;
    electrical  Net_59;
    electrical  Net_55;
    electrical  Net_57;
    electrical  Net_53;
    electrical  Net_39;
    electrical  Net_37;
    electrical  Net_15;
    electrical  Net_40;

	wire [4:0] tmpOE__HELFT_A_net;
	wire [4:0] tmpFB_4__HELFT_A_net;
	wire [4:0] tmpIO_4__HELFT_A_net;
	wire [0:0] tmpINTERRUPT_0__HELFT_A_net;
	electrical [0:0] tmpSIOVREF__HELFT_A_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(15'b110_110_110_110_110),
		  .ibuf_enabled(5'b1_1_1_1_1),
		  .init_dr_st(5'b0_0_0_0_0),
		  .input_clk_en(0),
		  .input_sync(5'b1_1_1_1_1),
		  .input_sync_mode(5'b0_0_0_0_0),
		  .intr_mode(10'b00_00_00_00_00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(",,,,"),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(5'b0_0_0_0_0),
		  .oe_reset(0),
		  .oe_sync(5'b0_0_0_0_0),
		  .output_clk_en(0),
		  .output_clock_mode(5'b0_0_0_0_0),
		  .output_conn(5'b0_0_0_0_0),
		  .output_mode(5'b0_0_0_0_0),
		  .output_reset(0),
		  .output_sync(5'b0_0_0_0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(",,,,"),
		  .pin_mode("OOOOO"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(5'b1_1_1_1_1),
		  .sio_ibuf(""),
		  .sio_info(10'b00_00_00_00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(5'b0_0_0_0_0),
		  .spanning(0),
		  .use_annotation(5'b1_1_1_1_1),
		  .vtrip(10'b10_10_10_10_10),
		  .width(5),
		  .ovt_hyst_trim(5'b0_0_0_0_0),
		  .ovt_needed(5'b0_0_0_0_0),
		  .ovt_slew_control(10'b00_00_00_00_00),
		  .input_buffer_sel(10'b00_00_00_00_00))
		HELFT_A
		 (.oe(tmpOE__HELFT_A_net),
		  .y({5'b0}),
		  .fb({tmpFB_4__HELFT_A_net[4:0]}),
		  .io({tmpIO_4__HELFT_A_net[4:0]}),
		  .siovref(tmpSIOVREF__HELFT_A_net),
		  .interrupt({tmpINTERRUPT_0__HELFT_A_net[0:0]}),
		  .annotation({Net_40, Net_39, Net_38, Net_37, Net_15}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__HELFT_A_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{5'b11111} : {5'b11111};

	wire [4:0] tmpOE__HELFT_B_net;
	wire [4:0] tmpFB_4__HELFT_B_net;
	wire [4:0] tmpIO_4__HELFT_B_net;
	wire [0:0] tmpINTERRUPT_0__HELFT_B_net;
	electrical [0:0] tmpSIOVREF__HELFT_B_net;

	cy_psoc3_pins_v1_10
		#(.id("aa112cf6-a7ec-481d-a7a4-8d5d6a712441"),
		  .drive_mode(15'b110_110_110_110_110),
		  .ibuf_enabled(5'b1_1_1_1_1),
		  .init_dr_st(5'b0_0_0_0_0),
		  .input_clk_en(0),
		  .input_sync(5'b1_1_1_1_1),
		  .input_sync_mode(5'b0_0_0_0_0),
		  .intr_mode(10'b00_00_00_00_00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(",,,,"),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(5'b0_0_0_0_0),
		  .oe_reset(0),
		  .oe_sync(5'b0_0_0_0_0),
		  .output_clk_en(0),
		  .output_clock_mode(5'b0_0_0_0_0),
		  .output_conn(5'b0_0_0_0_0),
		  .output_mode(5'b0_0_0_0_0),
		  .output_reset(0),
		  .output_sync(5'b0_0_0_0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(",,,,"),
		  .pin_mode("OOOOO"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(5'b1_1_1_1_1),
		  .sio_ibuf(""),
		  .sio_info(10'b00_00_00_00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(5'b0_0_0_0_0),
		  .spanning(0),
		  .use_annotation(5'b1_1_1_1_1),
		  .vtrip(10'b10_10_10_10_10),
		  .width(5),
		  .ovt_hyst_trim(5'b0_0_0_0_0),
		  .ovt_needed(5'b0_0_0_0_0),
		  .ovt_slew_control(10'b00_00_00_00_00),
		  .input_buffer_sel(10'b00_00_00_00_00))
		HELFT_B
		 (.oe(tmpOE__HELFT_B_net),
		  .y({5'b0}),
		  .fb({tmpFB_4__HELFT_B_net[4:0]}),
		  .io({tmpIO_4__HELFT_B_net[4:0]}),
		  .siovref(tmpSIOVREF__HELFT_B_net),
		  .interrupt({tmpINTERRUPT_0__HELFT_B_net[0:0]}),
		  .annotation({Net_60, Net_63, Net_43, Net_69, Net_72}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__HELFT_B_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{5'b11111} : {5'b11111};

    cy_annotation_universal_v1_0 D_1 (
        .connect({
            Net_50,
            Net_51
        })
    );
    defparam D_1.comp_name = "LED_v1_0";
    defparam D_1.port_names = "A, K";
    defparam D_1.width = 2;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_40,
            Net_50
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

	wire [0:0] tmpOE__Pin_1_net;
	wire [0:0] tmpFB_0__Pin_1_net;
	wire [0:0] tmpIO_0__Pin_1_net;
	wire [0:0] tmpINTERRUPT_0__Pin_1_net;
	electrical [0:0] tmpSIOVREF__Pin_1_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_1
		 (.oe(tmpOE__Pin_1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Pin_1_net[0:0]}),
		  .io({tmpIO_0__Pin_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_1_net),
		  .interrupt({tmpINTERRUPT_0__Pin_1_net[0:0]}),
		  .annotation({Net_48}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_51
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_39,
            Net_52
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 D_2 (
        .connect({
            Net_52,
            Net_53
        })
    );
    defparam D_2.comp_name = "LED_v1_0";
    defparam D_2.port_names = "A, K";
    defparam D_2.width = 2;

    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_53
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;

    cy_annotation_universal_v1_0 R_3 (
        .connect({
            Net_38,
            Net_54
        })
    );
    defparam R_3.comp_name = "Resistor_v1_0";
    defparam R_3.port_names = "T1, T2";
    defparam R_3.width = 2;

    cy_annotation_universal_v1_0 D_3 (
        .connect({
            Net_54,
            Net_55
        })
    );
    defparam D_3.comp_name = "LED_v1_0";
    defparam D_3.port_names = "A, K";
    defparam D_3.width = 2;

    cy_annotation_universal_v1_0 GND_3 (
        .connect({
            Net_55
        })
    );
    defparam GND_3.comp_name = "Gnd_v1_0";
    defparam GND_3.port_names = "T1";
    defparam GND_3.width = 1;

    cy_annotation_universal_v1_0 R_4 (
        .connect({
            Net_37,
            Net_56
        })
    );
    defparam R_4.comp_name = "Resistor_v1_0";
    defparam R_4.port_names = "T1, T2";
    defparam R_4.width = 2;

    cy_annotation_universal_v1_0 D_4 (
        .connect({
            Net_56,
            Net_57
        })
    );
    defparam D_4.comp_name = "LED_v1_0";
    defparam D_4.port_names = "A, K";
    defparam D_4.width = 2;

    cy_annotation_universal_v1_0 GND_4 (
        .connect({
            Net_57
        })
    );
    defparam GND_4.comp_name = "Gnd_v1_0";
    defparam GND_4.port_names = "T1";
    defparam GND_4.width = 1;

    cy_annotation_universal_v1_0 R_5 (
        .connect({
            Net_15,
            Net_58
        })
    );
    defparam R_5.comp_name = "Resistor_v1_0";
    defparam R_5.port_names = "T1, T2";
    defparam R_5.width = 2;

    cy_annotation_universal_v1_0 D_5 (
        .connect({
            Net_58,
            Net_59
        })
    );
    defparam D_5.comp_name = "LED_v1_0";
    defparam D_5.port_names = "A, K";
    defparam D_5.width = 2;

    cy_annotation_universal_v1_0 GND_5 (
        .connect({
            Net_59
        })
    );
    defparam GND_5.comp_name = "Gnd_v1_0";
    defparam GND_5.port_names = "T1";
    defparam GND_5.width = 1;

    cy_annotation_universal_v1_0 R_6 (
        .connect({
            Net_60,
            Net_61
        })
    );
    defparam R_6.comp_name = "Resistor_v1_0";
    defparam R_6.port_names = "T1, T2";
    defparam R_6.width = 2;

    cy_annotation_universal_v1_0 D_6 (
        .connect({
            Net_61,
            Net_62
        })
    );
    defparam D_6.comp_name = "LED_v1_0";
    defparam D_6.port_names = "A, K";
    defparam D_6.width = 2;

    cy_annotation_universal_v1_0 GND_6 (
        .connect({
            Net_62
        })
    );
    defparam GND_6.comp_name = "Gnd_v1_0";
    defparam GND_6.port_names = "T1";
    defparam GND_6.width = 1;

    cy_annotation_universal_v1_0 R_7 (
        .connect({
            Net_63,
            Net_64
        })
    );
    defparam R_7.comp_name = "Resistor_v1_0";
    defparam R_7.port_names = "T1, T2";
    defparam R_7.width = 2;

    cy_annotation_universal_v1_0 D_7 (
        .connect({
            Net_64,
            Net_65
        })
    );
    defparam D_7.comp_name = "LED_v1_0";
    defparam D_7.port_names = "A, K";
    defparam D_7.width = 2;

    cy_annotation_universal_v1_0 GND_7 (
        .connect({
            Net_65
        })
    );
    defparam GND_7.comp_name = "Gnd_v1_0";
    defparam GND_7.port_names = "T1";
    defparam GND_7.width = 1;

    cy_annotation_universal_v1_0 R_8 (
        .connect({
            Net_43,
            Net_67
        })
    );
    defparam R_8.comp_name = "Resistor_v1_0";
    defparam R_8.port_names = "T1, T2";
    defparam R_8.width = 2;

    cy_annotation_universal_v1_0 D_8 (
        .connect({
            Net_67,
            Net_68
        })
    );
    defparam D_8.comp_name = "LED_v1_0";
    defparam D_8.port_names = "A, K";
    defparam D_8.width = 2;

    cy_annotation_universal_v1_0 GND_8 (
        .connect({
            Net_68
        })
    );
    defparam GND_8.comp_name = "Gnd_v1_0";
    defparam GND_8.port_names = "T1";
    defparam GND_8.width = 1;

    cy_annotation_universal_v1_0 R_9 (
        .connect({
            Net_69,
            Net_70
        })
    );
    defparam R_9.comp_name = "Resistor_v1_0";
    defparam R_9.port_names = "T1, T2";
    defparam R_9.width = 2;

    cy_annotation_universal_v1_0 D_9 (
        .connect({
            Net_70,
            Net_71
        })
    );
    defparam D_9.comp_name = "LED_v1_0";
    defparam D_9.port_names = "A, K";
    defparam D_9.width = 2;

    cy_annotation_universal_v1_0 GND_9 (
        .connect({
            Net_71
        })
    );
    defparam GND_9.comp_name = "Gnd_v1_0";
    defparam GND_9.port_names = "T1";
    defparam GND_9.width = 1;

    cy_annotation_universal_v1_0 R_10 (
        .connect({
            Net_72,
            Net_73
        })
    );
    defparam R_10.comp_name = "Resistor_v1_0";
    defparam R_10.port_names = "T1, T2";
    defparam R_10.width = 2;

    cy_annotation_universal_v1_0 GND_10 (
        .connect({
            Net_74
        })
    );
    defparam GND_10.comp_name = "Gnd_v1_0";
    defparam GND_10.port_names = "T1";
    defparam GND_10.width = 1;

    cy_annotation_universal_v1_0 D_10 (
        .connect({
            Net_73,
            Net_74
        })
    );
    defparam D_10.comp_name = "LED_v1_0";
    defparam D_10.port_names = "A, K";
    defparam D_10.width = 2;



endmodule

