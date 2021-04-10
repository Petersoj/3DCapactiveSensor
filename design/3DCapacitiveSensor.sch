EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 7400 7500 0    50   ~ 0
3DCapacitiveSensor perfboard design
Wire Wire Line
	4500 2450 4500 2650
Wire Wire Line
	4500 2850 5000 2850
Wire Wire Line
	5000 2850 5000 2950
Connection ~ 4500 2850
Wire Wire Line
	4500 2850 4500 2950
Wire Wire Line
	4500 2850 4000 2850
Wire Wire Line
	4000 2850 4000 2950
$Comp
L Device:R_US R1
U 1 1 607267D1
P 4000 3100
F 0 "R1" H 4068 3146 50  0000 L CNN
F 1 "220K" H 4068 3055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4040 3090 50  0001 C CNN
F 3 "~" H 4000 3100 50  0001 C CNN
	1    4000 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 60726F97
P 4500 3100
F 0 "R3" H 4568 3146 50  0000 L CNN
F 1 "220K" H 4568 3055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4540 3090 50  0001 C CNN
F 3 "~" H 4500 3100 50  0001 C CNN
	1    4500 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R5
U 1 1 60727144
P 5000 3100
F 0 "R5" H 5068 3146 50  0000 L CNN
F 1 "220K" H 5068 3055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 5040 3090 50  0001 C CNN
F 3 "~" H 5000 3100 50  0001 C CNN
	1    5000 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R4
U 1 1 6072B2A7
P 4500 4100
F 0 "R4" H 4568 4146 50  0000 L CNN
F 1 "10K" H 4568 4055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4540 4090 50  0001 C CNN
F 3 "~" H 4500 4100 50  0001 C CNN
	1    4500 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3250 5000 3350
Wire Wire Line
	4500 3250 4500 3600
Wire Wire Line
	4000 3250 4000 3850
Connection ~ 5000 3350
Wire Wire Line
	5000 3350 5000 3950
Connection ~ 4500 3600
Wire Wire Line
	4500 3600 4500 3950
Connection ~ 4000 3850
Wire Wire Line
	4000 3850 4000 3950
Wire Wire Line
	4500 4250 4500 4600
Wire Wire Line
	4000 4250 4000 4600
Wire Wire Line
	5000 4250 5000 4600
Wire Wire Line
	5000 3350 6000 3350
Wire Wire Line
	4500 3600 6000 3600
Wire Wire Line
	4000 3850 6000 3850
Wire Wire Line
	4500 2650 5500 2650
Wire Wire Line
	5500 2650 5500 3300
Wire Wire Line
	5500 3300 5350 3300
Connection ~ 4500 2650
Wire Wire Line
	4500 2650 4500 2850
Wire Wire Line
	5500 3300 5650 3300
Connection ~ 5500 3300
Wire Wire Line
	5500 3300 5500 3400
Wire Wire Line
	5500 3400 5350 3400
Wire Wire Line
	5500 3400 5650 3400
Connection ~ 5500 3400
Wire Wire Line
	5500 3400 5500 3550
Wire Wire Line
	5500 3550 5650 3550
Wire Wire Line
	5500 3550 5350 3550
Connection ~ 5500 3550
Wire Wire Line
	5500 3550 5500 3650
Wire Wire Line
	5500 3650 5650 3650
Wire Wire Line
	5500 3650 5350 3650
Connection ~ 5500 3650
Wire Wire Line
	5500 3650 5500 3800
Wire Wire Line
	5500 3800 5650 3800
Wire Wire Line
	5500 3800 5350 3800
Connection ~ 5500 3800
Wire Wire Line
	5500 3800 5500 3900
Wire Wire Line
	5500 3900 5650 3900
Wire Wire Line
	5500 3900 5350 3900
Connection ~ 5500 3900
Text Label 5050 2650 0    50   ~ 0
shield_wire
$Comp
L Connector:Conn_01x01_Male J6
U 1 1 60735CD0
P 6200 3850
F 0 "J6" H 6172 3782 50  0001 R CNN
F 1 "Z_plate" H 6172 3828 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 6200 3850 50  0001 C CNN
F 3 "~" H 6200 3850 50  0001 C CNN
	1    6200 3850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J5
U 1 1 607354B4
P 6200 3600
F 0 "J5" H 6172 3532 50  0001 R CNN
F 1 "Y_plate" H 6172 3578 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 6200 3600 50  0001 C CNN
F 3 "~" H 6200 3600 50  0001 C CNN
	1    6200 3600
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J4
U 1 1 607342FB
P 6200 3350
F 0 "J4" H 6172 3282 50  0001 R CNN
F 1 "X_plate" H 6172 3328 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 6200 3350 50  0001 C CNN
F 3 "~" H 6200 3350 50  0001 C CNN
	1    6200 3350
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J7
U 1 1 60742720
P 4500 2250
F 0 "J7" V 4562 2294 50  0001 L CNN
F 1 "3V" V 4608 2294 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 4500 2250 50  0001 C CNN
F 3 "~" H 4500 2250 50  0001 C CNN
	1    4500 2250
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x06_Female J1
U 1 1 60746578
P 4550 5250
F 0 "J1" V 4396 5498 50  0001 L CNN
F 1 "Pin Socket" V 4487 5498 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 4550 5250 50  0001 C CNN
F 3 "~" H 4550 5250 50  0001 C CNN
	1    4550 5250
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 4600 4250 4600
Wire Wire Line
	4250 4600 4250 5050
Wire Wire Line
	4250 4600 4350 4600
Wire Wire Line
	4350 4600 4350 5050
Connection ~ 4250 4600
Wire Wire Line
	4500 4600 4450 4600
Wire Wire Line
	4450 4600 4450 5050
Wire Wire Line
	4500 4600 4550 4600
Wire Wire Line
	4550 4600 4550 5050
Connection ~ 4500 4600
Wire Wire Line
	5000 4600 4750 4600
Wire Wire Line
	4650 4600 4650 5050
Wire Wire Line
	4750 5050 4750 4600
Connection ~ 4750 4600
Wire Wire Line
	4750 4600 4650 4600
Text Label 4250 5000 1    50   ~ 0
Z_ADC
Text Label 4350 5000 1    50   ~ 0
Z_pin
Text Label 4450 5000 1    50   ~ 0
Y_ADC
Text Label 4550 5000 1    50   ~ 0
Y_pin
Text Label 4650 5000 1    50   ~ 0
X_ADC
Text Label 4750 5000 1    50   ~ 0
X_pin
$Comp
L Device:R_US R6
U 1 1 6072B5B0
P 5000 4100
F 0 "R6" H 5068 4146 50  0000 L CNN
F 1 "10K" H 5068 4055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 5040 4090 50  0001 C CNN
F 3 "~" H 5000 4100 50  0001 C CNN
	1    5000 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 6072A903
P 4000 4100
F 0 "R2" H 4068 4146 50  0000 L CNN
F 1 "10K" H 4068 4055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4040 4090 50  0001 C CNN
F 3 "~" H 4000 4100 50  0001 C CNN
	1    4000 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J2
U 1 1 60768D29
P 5850 3400
F 0 "J2" H 5822 3332 50  0001 R CNN
F 1 "X_shield" H 5822 3378 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 5850 3400 50  0001 C CNN
F 3 "~" H 5850 3400 50  0001 C CNN
	1    5850 3400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J3
U 1 1 6076926F
P 5850 3650
F 0 "J3" H 5822 3582 50  0001 R CNN
F 1 "Y_shield" H 5822 3628 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 5850 3650 50  0001 C CNN
F 3 "~" H 5850 3650 50  0001 C CNN
	1    5850 3650
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J8
U 1 1 60769800
P 5850 3900
F 0 "J8" H 5822 3832 50  0001 R CNN
F 1 "Z_shield" H 5822 3878 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 5850 3900 50  0001 C CNN
F 3 "~" H 5850 3900 50  0001 C CNN
	1    5850 3900
	-1   0    0    1   
$EndComp
$EndSCHEMATC
