void getback(void){
	int multiply = 6;
	time1 = 3*multiply;
	addMotorParams(32,1,center[0]+(-17));
	addMotorParams(32,2,center[1]+(17));
	addMotorParams(32,3,center[2]+(-468));
	addMotorParams(32,4,center[3]+(744));
	addMotorParams(32,5,center[4]+(395));
	addMotorParams(32,6,center[5]+(18));
	addMotorParams(32,10,center[6]+(-12));
	addMotorParams(32,11,center[7]+(0));
	addMotorParams(32,12,center[8]+(460));
	addMotorParams(32,13,center[9]+(-757));
	addMotorParams(32,14,center[10]+(-411));
	addMotorParams(32,15,center[11]+(0));
	addMotorParams(32,17,center[12]+(-320));
	addMotorParams(32,18,center[13]+(-50));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-188));
	addMotorParams(32,26,center[16]+(352));
	addMotorParams(32,27,center[17]+(75));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(188));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 3*multiply;
	addMotorParams(32,1,center[0]+(-17));
	addMotorParams(32,2,center[1]+(0));
	addMotorParams(32,3,center[2]+(366));
	addMotorParams(32,4,center[3]+(1217));
	addMotorParams(32,5,center[4]+(539));
	addMotorParams(32,6,center[5]+(18));
	addMotorParams(32,10,center[6]+(-12));
	addMotorParams(32,11,center[7]+(0));
	addMotorParams(32,12,center[8]+(-339));
	addMotorParams(32,13,center[9]+(-1231));
	addMotorParams(32,14,center[10]+(-531));
	addMotorParams(32,15,center[11]+(0));
	addMotorParams(32,17,center[12]+(-2020));
	addMotorParams(32,18,center[13]+(-50));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-903));
	addMotorParams(32,26,center[16]+(2047));
	addMotorParams(32,27,center[17]+(75));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(918));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 6*multiply;
	addMotorParams(32,1,center[0]+(-21));
	addMotorParams(32,2,center[1]+(2));
	addMotorParams(32,3,center[2]+(292));
	addMotorParams(32,4,center[3]+(1256));
	addMotorParams(32,5,center[4]+(881));
	addMotorParams(32,6,center[5]+(4));
	addMotorParams(32,10,center[6]+(-15));
	addMotorParams(32,11,center[7]+(3));
	addMotorParams(32,12,center[8]+(-295));
	addMotorParams(32,13,center[9]+(-1257));
	addMotorParams(32,14,center[10]+(-892));
	addMotorParams(32,15,center[11]+(-2));
	addMotorParams(32,17,center[12]+(-675));
	addMotorParams(32,18,center[13]+(-52));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(340));
	addMotorParams(32,26,center[16]+(703));
	addMotorParams(32,27,center[17]+(43));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(-330));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 3*multiply;
	addMotorParams(32,1,center[0]+(-17));
	addMotorParams(32,2,center[1]+(6));
	addMotorParams(32,3,center[2]+(-50));
	addMotorParams(32,4,center[3]+(1150));
	addMotorParams(32,5,center[4]+(891));
	addMotorParams(32,6,center[5]+(8));
	addMotorParams(32,10,center[6]+(-6));
	addMotorParams(32,11,center[7]+(4));
	addMotorParams(32,12,center[8]+(64));
	addMotorParams(32,13,center[9]+(-1143));
	addMotorParams(32,14,center[10]+(-893));
	addMotorParams(32,15,center[11]+(7));
	addMotorParams(32,17,center[12]+(78));
	addMotorParams(32,18,center[13]+(-17));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-1031));
	addMotorParams(32,26,center[16]+(-85));
	addMotorParams(32,27,center[17]+(72));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(990));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 4*multiply;
	addMotorParams(32,1,center[0]+(-18));
	addMotorParams(32,2,center[1]+(18));
	addMotorParams(32,3,center[2]+(-466));
	addMotorParams(32,4,center[3]+(740));
	addMotorParams(32,5,center[4]+(407));
	addMotorParams(32,6,center[5]+(16));
	addMotorParams(32,10,center[6]+(-14));
	addMotorParams(32,11,center[7]+(3));
	addMotorParams(32,12,center[8]+(488));
	addMotorParams(32,13,center[9]+(-751));
	addMotorParams(32,14,center[10]+(-384));
	addMotorParams(32,15,center[11]+(0));
	addMotorParams(32,17,center[12]+(-314));
	addMotorParams(32,18,center[13]+(-52));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-188));
	addMotorParams(32,26,center[16]+(346));
	addMotorParams(32,27,center[17]+(76));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(186));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

}

void getfront(void){
	int multiply = 5;
	set_center();
	time1 = 2*multiply;
	addMotorParams(32,1,center[0]+(-17));
	addMotorParams(32,2,center[1]+(0));
	addMotorParams(32,3,center[2]+(-1269));
	addMotorParams(32,4,center[3]+(1435));
	addMotorParams(32,5,center[4]+(557));
	addMotorParams(32,6,center[5]+(18));
	addMotorParams(32,10,center[6]+(-12));
	addMotorParams(32,11,center[7]+(0));
	addMotorParams(32,12,center[8]+(1286));
	addMotorParams(32,13,center[9]+(-1435));
	addMotorParams(32,14,center[10]+(-547));
	addMotorParams(32,15,center[11]+(0));
	addMotorParams(32,17,center[12]+(155));
	addMotorParams(32,18,center[13]+(835));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-188));
	addMotorParams(32,26,center[16]+(-188));
	addMotorParams(32,27,center[17]+(-916));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(188));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 2*multiply;
	addMotorParams(32,1,center[0]+(-17));
	addMotorParams(32,2,center[1]+(0));
	addMotorParams(32,3,center[2]+(-1286));
	addMotorParams(32,4,center[3]+(1450));
	addMotorParams(32,5,center[4]+(556));
	addMotorParams(32,6,center[5]+(18));
	addMotorParams(32,10,center[6]+(-12));
	addMotorParams(32,11,center[7]+(0));
	addMotorParams(32,12,center[8]+(1299));
	addMotorParams(32,13,center[9]+(-1453));
	addMotorParams(32,14,center[10]+(-544));
	addMotorParams(32,15,center[11]+(0));
	addMotorParams(32,17,center[12]+(152));
	addMotorParams(32,18,center[13]+(830));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-188));
	addMotorParams(32,26,center[16]+(-187));
	addMotorParams(32,27,center[17]+(-911));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(188));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 2*multiply;
	addMotorParams(32,1,center[0]+(-17));
	addMotorParams(32,2,center[1]+(17));
	addMotorParams(32,3,center[2]+(-1300));
	addMotorParams(32,4,center[3]+(1458));
	addMotorParams(32,5,center[4]+(554));
	addMotorParams(32,6,center[5]+(18));
	addMotorParams(32,10,center[6]+(-12));
	addMotorParams(32,11,center[7]+(17));
	addMotorParams(32,12,center[8]+(1310));
	addMotorParams(32,13,center[9]+(-1460));
	addMotorParams(32,14,center[10]+(-547));
	addMotorParams(32,15,center[11]+(0));
	addMotorParams(32,17,center[12]+(-620));
	addMotorParams(32,18,center[13]+(-50));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-1548));
	addMotorParams(32,26,center[16]+(652));
	addMotorParams(32,27,center[17]+(75));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(1552));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 2*multiply;
	addMotorParams(32,1,center[0]+(-17));
	addMotorParams(32,2,center[1]+(17));
	addMotorParams(32,3,center[2]+(-1300));
	addMotorParams(32,4,center[3]+(1458));
	addMotorParams(32,5,center[4]+(554));
	addMotorParams(32,6,center[5]+(18));
	addMotorParams(32,10,center[6]+(-12));
	addMotorParams(32,11,center[7]+(17));
	addMotorParams(32,12,center[8]+(1310));
	addMotorParams(32,13,center[9]+(-1462));
	addMotorParams(32,14,center[10]+(-547));
	addMotorParams(32,15,center[11]+(0));
	addMotorParams(32,17,center[12]+(-20));
	addMotorParams(32,18,center[13]+(-50));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-1548));
	addMotorParams(32,26,center[16]+(52));
	addMotorParams(32,27,center[17]+(75));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(1552));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 7*multiply;
	addMotorParams(32,1,center[0]+(-15));
	addMotorParams(32,2,center[1]+(0));
	addMotorParams(32,3,center[2]+(-1419));
	addMotorParams(32,4,center[3]+(1469));
	addMotorParams(32,5,center[4]+(554));
	addMotorParams(32,6,center[5]+(18));
	addMotorParams(32,10,center[6]+(-14));
	addMotorParams(32,11,center[7]+(0));
	addMotorParams(32,12,center[8]+(1398));
	addMotorParams(32,13,center[9]+(-1454));
	addMotorParams(32,14,center[10]+(-547));
	addMotorParams(32,15,center[11]+(0));
	addMotorParams(32,17,center[12]+(569));
	addMotorParams(32,18,center[13]+(-58));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(262));
	addMotorParams(32,26,center[16]+(-593));
	addMotorParams(32,27,center[17]+(75));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(-309));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

	time1 = 4*multiply;
	addMotorParams(32,1,center[0]+(-5));
	addMotorParams(32,2,center[1]+(14));
	addMotorParams(32,3,center[2]+(-431));
	addMotorParams(32,4,center[3]+(701));
	addMotorParams(32,5,center[4]+(363));
	addMotorParams(32,6,center[5]+(17));
	addMotorParams(32,10,center[6]+(-10));
	addMotorParams(32,11,center[7]+(6));
	addMotorParams(32,12,center[8]+(447));
	addMotorParams(32,13,center[9]+(-684));
	addMotorParams(32,14,center[10]+(-358));
	addMotorParams(32,15,center[11]+(-5));
	addMotorParams(32,17,center[12]+(-78));
	addMotorParams(32,18,center[13]+(-53));
	addMotorParams(32,19,center[14]+(0));
	addMotorParams(32,20,center[15]+(-192));
	addMotorParams(32,26,center[16]+(72));
	addMotorParams(32,27,center[17]+(72));
	addMotorParams(32,28,center[18]+(0));
	addMotorParams(32,29,center[19]+(191));
	movingSpeed_generator();
	while(time1s!=0) {run_joint();}

}
