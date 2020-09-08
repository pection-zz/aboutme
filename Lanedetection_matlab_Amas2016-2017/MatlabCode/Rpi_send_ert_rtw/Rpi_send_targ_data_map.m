  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (dc2k4x0veea)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dc2k4x0veea.FindLocalMaxima_threshold
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% dc2k4x0veea.Rotate_fillVal
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dc2k4x0veea.Rotate_fillVal_ik1xpen0rm
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% dc2k4x0veea.DigitalRead_SampleTime
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dc2k4x0veea.Startidxcrop_Value
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dc2k4x0veea.StartidxW_Value
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dc2k4x0veea.blurmatrix_Value
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dc2k4x0veea.sobelverticalmatrix_Value
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 28;
	
	  ;% dc2k4x0veea.removeboundary_Value
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 37;
	
	  ;% dc2k4x0veea.Constant_Value
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 38;
	
	  ;% dc2k4x0veea.Constant_Value_igrygp1sfa
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 39;
	
	  ;% dc2k4x0veea.Startidxcrop_Value_n5qw4ehq0c
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 40;
	
	  ;% dc2k4x0veea.StartidxW_Value_kmf41b2fgv
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 41;
	
	  ;% dc2k4x0veea.blurmatrix_Value_ie1lp0mdke
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 42;
	
	  ;% dc2k4x0veea.sobelverticalmatrix__bxm0gvh1s4
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 67;
	
	  ;% dc2k4x0veea.removeboundary_Value_ccenk2g1kp
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 76;
	
	  ;% dc2k4x0veea.Saturation2_UpperSat
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 77;
	
	  ;% dc2k4x0veea.Saturation2_LowerSat
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 78;
	
	  ;% dc2k4x0veea.Constant3_Value
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 79;
	
	  ;% dc2k4x0veea.Gain_Gain
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 80;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% dc2k4x0veea.n2gcigz0ph.SignSteer_Value
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dc2k4x0veea.n2gcigz0ph.SteeringAngle_Value
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dc2k4x0veea.n2gcigz0ph.SignLidar_Value
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% dc2k4x0veea.pvpaaioyj53.SignSteer_Value
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dc2k4x0veea.pvpaaioyj53.SteeringAngle_Value
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dc2k4x0veea.pvpaaioyj53.SignLidar_Value
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% dc2k4x0veea.a4i0imrdpns.Constant_Value
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dc2k4x0veea.a4i0imrdpns.Constant1_Value
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% dc2k4x0veea.m5sfktesnxt.Constant_Value
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dc2k4x0veea.m5sfktesnxt.Constant1_Value
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 25;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (dd3fzvtkdqa)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.b4wklx51lo
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dd3fzvtkdqa.n24ve5fokh
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 8400;
	
	  ;% dd3fzvtkdqa.dmhjb02ndn
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 15900;
	
	  ;% dd3fzvtkdqa.bhqffz4dsu
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 129300;
	
	  ;% dd3fzvtkdqa.ddxbpawgkb
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 138900;
	
	  ;% dd3fzvtkdqa.gj2gfczohq
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 149396;
	
	  ;% dd3fzvtkdqa.hiulscxttb
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 160352;
	
	  ;% dd3fzvtkdqa.msfdni5ax1
	  section.data(8).logicalSrcIdx = 29;
	  section.data(8).dtTransOffset = 167852;
	
	  ;% dd3fzvtkdqa.klfl11nepo
	  section.data(9).logicalSrcIdx = 30;
	  section.data(9).dtTransOffset = 175352;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.impfa1u1kz
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.aoi3n2fwij
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dd3fzvtkdqa.iki5dy3umr
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 7500;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.emx253zj43
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dd3fzvtkdqa.cyahjfjsvx
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 360;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.kpbf1gwav4
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dd3fzvtkdqa.e4c5ez1w5k
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dd3fzvtkdqa.cqxr02d2fx
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dd3fzvtkdqa.ig3tkxlbg1
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dd3fzvtkdqa.fhsxq4px1q
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dd3fzvtkdqa.dujxm2lxpt
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% dd3fzvtkdqa.epryfxs4bu
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% dd3fzvtkdqa.oh000mn5gx
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% dd3fzvtkdqa.dpsejoqcjz
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% dd3fzvtkdqa.l0fmk5hgkc
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% dd3fzvtkdqa.niqszzr0jq
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 10;
	
	  ;% dd3fzvtkdqa.b4vaithuaa
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 11;
	
	  ;% dd3fzvtkdqa.gc0ljtpowy
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 12;
	
	  ;% dd3fzvtkdqa.nn3edl40ev
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 13;
	
	  ;% dd3fzvtkdqa.mhriz5lnbl
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 14;
	
	  ;% dd3fzvtkdqa.gnvsskzlg1
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 15;
	
	  ;% dd3fzvtkdqa.fyjlwgl3tx
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 16;
	
	  ;% dd3fzvtkdqa.koxurt4gca
	  section.data(18).logicalSrcIdx = 23;
	  section.data(18).dtTransOffset = 17;
	
	  ;% dd3fzvtkdqa.jbfmo4r41z
	  section.data(19).logicalSrcIdx = 24;
	  section.data(19).dtTransOffset = 9233;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.flhysyliju
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dd3fzvtkdqa.j52zboclv1
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.dqpj0okztm
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dd3fzvtkdqa.iyurtpxzx2
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 19200;
	
	  ;% dd3fzvtkdqa.ett2ngk20z
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 38400;
	
	  ;% dd3fzvtkdqa.aizf3szy2t
	  section.data(4).logicalSrcIdx = 36;
	  section.data(4).dtTransOffset = 57600;
	
	  ;% dd3fzvtkdqa.lk41etk4oh
	  section.data(5).logicalSrcIdx = 37;
	  section.data(5).dtTransOffset = 115200;
	
	  ;% dd3fzvtkdqa.mqfgg2lnjt
	  section.data(6).logicalSrcIdx = 38;
	  section.data(6).dtTransOffset = 134400;
	
	  ;% dd3fzvtkdqa.kyiulwiy23
	  section.data(7).logicalSrcIdx = 39;
	  section.data(7).dtTransOffset = 142800;
	
	  ;% dd3fzvtkdqa.abpuraqvza
	  section.data(8).logicalSrcIdx = 40;
	  section.data(8).dtTransOffset = 200400;
	
	  ;% dd3fzvtkdqa.jegwnysrsc
	  section.data(9).logicalSrcIdx = 41;
	  section.data(9).dtTransOffset = 219600;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.gbn4e1tlqu
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.iw32xow40a
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.n2gcigz0ph.hzqmsdgovg
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.n2gcigz0ph.eqesybfsce.jee05ra2mq
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.n2gcigz0ph.mzgaeaul4e.eil2v0weg4
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.n2gcigz0ph.hnrbdjhutz.b4xjfl3sao
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.pvpaaioyj53.hzqmsdgovg
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.pvpaaioyj53.eqesybfsce.jee05ra2mq
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.pvpaaioyj53.mzgaeaul4e.eil2v0weg4
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.pvpaaioyj53.hnrbdjhutz.b4xjfl3sao
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.a4i0imrdpns.nblxcrecif
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.a4i0imrdpns.nd00y3zbs4.jee05ra2mq
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.a4i0imrdpns.oovyw3tyas.eil2v0weg4
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.a4i0imrdpns.k5t12rc2tj.b4xjfl3sao
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.m5sfktesnxt.jep5twcx1b
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.m5sfktesnxt.foqbxo3nakd.jee05ra2mq
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.m5sfktesnxt.ovcn4usrdyr.eil2v0weg4
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dd3fzvtkdqa.m5sfktesnxt.m25rcjiptsn.b4xjfl3sao
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(25) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 23;
    sectIdxOffset = 25;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (bkvdms3q054)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.ljo0x4o13q
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.km14arqr5n
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% bkvdms3q054.kdhj310ykv
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bkvdms3q054.khb3lnohuf
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% bkvdms3q054.firqu34xve.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bkvdms3q054.al4d4p2vry.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bkvdms3q054.omvvvlz2un
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 80;
      section.data(80)  = dumData; %prealloc
      
	  ;% bkvdms3q054.prdo3052iv
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bkvdms3q054.nmu4aldyez
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 2;
	
	  ;% bkvdms3q054.j5z3i25qor
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 4;
	
	  ;% bkvdms3q054.layo4sbsnq
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 6;
	
	  ;% bkvdms3q054.dsobbc5toa
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 8;
	
	  ;% bkvdms3q054.oluze4j523
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 10;
	
	  ;% bkvdms3q054.hfym4peq3i
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 12;
	
	  ;% bkvdms3q054.prynx4ihg1
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 22;
	
	  ;% bkvdms3q054.ekrfmetogi
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 32;
	
	  ;% bkvdms3q054.bieefwngkm
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 34;
	
	  ;% bkvdms3q054.jvacd1cugu
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 36;
	
	  ;% bkvdms3q054.evxz3ypqr3
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 38;
	
	  ;% bkvdms3q054.cfv0e5s1o0
	  section.data(13).logicalSrcIdx = 19;
	  section.data(13).dtTransOffset = 40;
	
	  ;% bkvdms3q054.mapnisw2sc
	  section.data(14).logicalSrcIdx = 20;
	  section.data(14).dtTransOffset = 42;
	
	  ;% bkvdms3q054.ejwfel4fnv
	  section.data(15).logicalSrcIdx = 21;
	  section.data(15).dtTransOffset = 44;
	
	  ;% bkvdms3q054.oddzgmgymg
	  section.data(16).logicalSrcIdx = 22;
	  section.data(16).dtTransOffset = 46;
	
	  ;% bkvdms3q054.gsdcplgdjn
	  section.data(17).logicalSrcIdx = 23;
	  section.data(17).dtTransOffset = 48;
	
	  ;% bkvdms3q054.dz2qbpxgsz
	  section.data(18).logicalSrcIdx = 24;
	  section.data(18).dtTransOffset = 50;
	
	  ;% bkvdms3q054.fg0dqr0mqq
	  section.data(19).logicalSrcIdx = 25;
	  section.data(19).dtTransOffset = 52;
	
	  ;% bkvdms3q054.p0xpc3gr05
	  section.data(20).logicalSrcIdx = 26;
	  section.data(20).dtTransOffset = 54;
	
	  ;% bkvdms3q054.ooamhdqz1d
	  section.data(21).logicalSrcIdx = 27;
	  section.data(21).dtTransOffset = 64;
	
	  ;% bkvdms3q054.bp5x3xsboj
	  section.data(22).logicalSrcIdx = 28;
	  section.data(22).dtTransOffset = 74;
	
	  ;% bkvdms3q054.jnrnsil5tz
	  section.data(23).logicalSrcIdx = 29;
	  section.data(23).dtTransOffset = 76;
	
	  ;% bkvdms3q054.erhejysmyv
	  section.data(24).logicalSrcIdx = 30;
	  section.data(24).dtTransOffset = 78;
	
	  ;% bkvdms3q054.azzyh1alyd
	  section.data(25).logicalSrcIdx = 31;
	  section.data(25).dtTransOffset = 80;
	
	  ;% bkvdms3q054.hpr2r0h4jh
	  section.data(26).logicalSrcIdx = 32;
	  section.data(26).dtTransOffset = 82;
	
	  ;% bkvdms3q054.bcdeufrqaz
	  section.data(27).logicalSrcIdx = 33;
	  section.data(27).dtTransOffset = 84;
	
	  ;% bkvdms3q054.inkdv4y0pm
	  section.data(28).logicalSrcIdx = 34;
	  section.data(28).dtTransOffset = 86;
	
	  ;% bkvdms3q054.jt1js2olu0
	  section.data(29).logicalSrcIdx = 35;
	  section.data(29).dtTransOffset = 88;
	
	  ;% bkvdms3q054.miwlpgya4j
	  section.data(30).logicalSrcIdx = 36;
	  section.data(30).dtTransOffset = 90;
	
	  ;% bkvdms3q054.e3ipnic11b
	  section.data(31).logicalSrcIdx = 37;
	  section.data(31).dtTransOffset = 92;
	
	  ;% bkvdms3q054.olr4yemj2l
	  section.data(32).logicalSrcIdx = 38;
	  section.data(32).dtTransOffset = 94;
	
	  ;% bkvdms3q054.izavsvlrbo
	  section.data(33).logicalSrcIdx = 39;
	  section.data(33).dtTransOffset = 96;
	
	  ;% bkvdms3q054.emn33opu5w
	  section.data(34).logicalSrcIdx = 40;
	  section.data(34).dtTransOffset = 106;
	
	  ;% bkvdms3q054.c2wa4ffjsm
	  section.data(35).logicalSrcIdx = 41;
	  section.data(35).dtTransOffset = 116;
	
	  ;% bkvdms3q054.gahh5sd14n
	  section.data(36).logicalSrcIdx = 42;
	  section.data(36).dtTransOffset = 118;
	
	  ;% bkvdms3q054.bpn2tz5suj
	  section.data(37).logicalSrcIdx = 43;
	  section.data(37).dtTransOffset = 120;
	
	  ;% bkvdms3q054.kuzd0jfkk1
	  section.data(38).logicalSrcIdx = 44;
	  section.data(38).dtTransOffset = 122;
	
	  ;% bkvdms3q054.cpnztcdn0v
	  section.data(39).logicalSrcIdx = 45;
	  section.data(39).dtTransOffset = 124;
	
	  ;% bkvdms3q054.az20vfiipf
	  section.data(40).logicalSrcIdx = 46;
	  section.data(40).dtTransOffset = 126;
	
	  ;% bkvdms3q054.bvinhjdq5n
	  section.data(41).logicalSrcIdx = 47;
	  section.data(41).dtTransOffset = 128;
	
	  ;% bkvdms3q054.jayt3zohb3
	  section.data(42).logicalSrcIdx = 48;
	  section.data(42).dtTransOffset = 130;
	
	  ;% bkvdms3q054.jg3hkpspaq
	  section.data(43).logicalSrcIdx = 49;
	  section.data(43).dtTransOffset = 132;
	
	  ;% bkvdms3q054.jywiwdvgr4
	  section.data(44).logicalSrcIdx = 50;
	  section.data(44).dtTransOffset = 134;
	
	  ;% bkvdms3q054.f5khk3codj
	  section.data(45).logicalSrcIdx = 51;
	  section.data(45).dtTransOffset = 136;
	
	  ;% bkvdms3q054.kodez0bod2
	  section.data(46).logicalSrcIdx = 52;
	  section.data(46).dtTransOffset = 138;
	
	  ;% bkvdms3q054.m3ier2d5qe
	  section.data(47).logicalSrcIdx = 53;
	  section.data(47).dtTransOffset = 148;
	
	  ;% bkvdms3q054.aheyizwkvf
	  section.data(48).logicalSrcIdx = 54;
	  section.data(48).dtTransOffset = 158;
	
	  ;% bkvdms3q054.bgoeok224g
	  section.data(49).logicalSrcIdx = 55;
	  section.data(49).dtTransOffset = 160;
	
	  ;% bkvdms3q054.jufq4od52a
	  section.data(50).logicalSrcIdx = 56;
	  section.data(50).dtTransOffset = 162;
	
	  ;% bkvdms3q054.gonzia1ckx
	  section.data(51).logicalSrcIdx = 57;
	  section.data(51).dtTransOffset = 164;
	
	  ;% bkvdms3q054.haaabvvhpz
	  section.data(52).logicalSrcIdx = 58;
	  section.data(52).dtTransOffset = 166;
	
	  ;% bkvdms3q054.lralyzlgrt
	  section.data(53).logicalSrcIdx = 59;
	  section.data(53).dtTransOffset = 168;
	
	  ;% bkvdms3q054.ifai0prty4
	  section.data(54).logicalSrcIdx = 60;
	  section.data(54).dtTransOffset = 169;
	
	  ;% bkvdms3q054.mgkz1qbzyb
	  section.data(55).logicalSrcIdx = 61;
	  section.data(55).dtTransOffset = 170;
	
	  ;% bkvdms3q054.jvyu23vekd
	  section.data(56).logicalSrcIdx = 62;
	  section.data(56).dtTransOffset = 171;
	
	  ;% bkvdms3q054.jdrdwj3je5
	  section.data(57).logicalSrcIdx = 63;
	  section.data(57).dtTransOffset = 177;
	
	  ;% bkvdms3q054.e3q1lamfuz
	  section.data(58).logicalSrcIdx = 64;
	  section.data(58).dtTransOffset = 183;
	
	  ;% bkvdms3q054.nw4epme52b
	  section.data(59).logicalSrcIdx = 65;
	  section.data(59).dtTransOffset = 189;
	
	  ;% bkvdms3q054.abyps11r0r
	  section.data(60).logicalSrcIdx = 66;
	  section.data(60).dtTransOffset = 195;
	
	  ;% bkvdms3q054.edmgtkvg3r
	  section.data(61).logicalSrcIdx = 67;
	  section.data(61).dtTransOffset = 201;
	
	  ;% bkvdms3q054.fv3j23x2eo
	  section.data(62).logicalSrcIdx = 68;
	  section.data(62).dtTransOffset = 207;
	
	  ;% bkvdms3q054.n1d5unc3bz
	  section.data(63).logicalSrcIdx = 69;
	  section.data(63).dtTransOffset = 213;
	
	  ;% bkvdms3q054.b0nopngjl0
	  section.data(64).logicalSrcIdx = 70;
	  section.data(64).dtTransOffset = 219;
	
	  ;% bkvdms3q054.ihvzpmr2om
	  section.data(65).logicalSrcIdx = 71;
	  section.data(65).dtTransOffset = 225;
	
	  ;% bkvdms3q054.jwmiyzemqy
	  section.data(66).logicalSrcIdx = 72;
	  section.data(66).dtTransOffset = 231;
	
	  ;% bkvdms3q054.p2s5bzhstl
	  section.data(67).logicalSrcIdx = 73;
	  section.data(67).dtTransOffset = 237;
	
	  ;% bkvdms3q054.henzcqaidf
	  section.data(68).logicalSrcIdx = 74;
	  section.data(68).dtTransOffset = 243;
	
	  ;% bkvdms3q054.brcwsedvjf
	  section.data(69).logicalSrcIdx = 75;
	  section.data(69).dtTransOffset = 249;
	
	  ;% bkvdms3q054.p5mdcp4mej
	  section.data(70).logicalSrcIdx = 76;
	  section.data(70).dtTransOffset = 255;
	
	  ;% bkvdms3q054.cf50mbhhui
	  section.data(71).logicalSrcIdx = 77;
	  section.data(71).dtTransOffset = 261;
	
	  ;% bkvdms3q054.py45swmmqa
	  section.data(72).logicalSrcIdx = 78;
	  section.data(72).dtTransOffset = 267;
	
	  ;% bkvdms3q054.jrk23enxmi
	  section.data(73).logicalSrcIdx = 79;
	  section.data(73).dtTransOffset = 273;
	
	  ;% bkvdms3q054.iple0fkfe3
	  section.data(74).logicalSrcIdx = 80;
	  section.data(74).dtTransOffset = 279;
	
	  ;% bkvdms3q054.hyg0ll4e3s
	  section.data(75).logicalSrcIdx = 81;
	  section.data(75).dtTransOffset = 280;
	
	  ;% bkvdms3q054.gzodq1rjnz
	  section.data(76).logicalSrcIdx = 82;
	  section.data(76).dtTransOffset = 281;
	
	  ;% bkvdms3q054.fbaakrrq5g
	  section.data(77).logicalSrcIdx = 83;
	  section.data(77).dtTransOffset = 282;
	
	  ;% bkvdms3q054.lusfjjiaka
	  section.data(78).logicalSrcIdx = 84;
	  section.data(78).dtTransOffset = 283;
	
	  ;% bkvdms3q054.czbrwvedvx
	  section.data(79).logicalSrcIdx = 85;
	  section.data(79).dtTransOffset = 284;
	
	  ;% bkvdms3q054.aphljv5irv
	  section.data(80).logicalSrcIdx = 86;
	  section.data(80).dtTransOffset = 288;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% bkvdms3q054.o1j1fz14up
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bkvdms3q054.pvqhayaa0x
	  section.data(2).logicalSrcIdx = 88;
	  section.data(2).dtTransOffset = 57600;
	
	  ;% bkvdms3q054.csabxda5zj
	  section.data(3).logicalSrcIdx = 89;
	  section.data(3).dtTransOffset = 115200;
	
	  ;% bkvdms3q054.dos1c0xwtj
	  section.data(4).logicalSrcIdx = 90;
	  section.data(4).dtTransOffset = 115201;
	
	  ;% bkvdms3q054.cv0w1oxknb
	  section.data(5).logicalSrcIdx = 91;
	  section.data(5).dtTransOffset = 115202;
	
	  ;% bkvdms3q054.h5mkarjxsq
	  section.data(6).logicalSrcIdx = 92;
	  section.data(6).dtTransOffset = 115203;
	
	  ;% bkvdms3q054.hkgbhgncvw
	  section.data(7).logicalSrcIdx = 93;
	  section.data(7).dtTransOffset = 115204;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% bkvdms3q054.co3egiqvee
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bkvdms3q054.jl1zhg2gzx
	  section.data(2).logicalSrcIdx = 95;
	  section.data(2).dtTransOffset = 2;
	
	  ;% bkvdms3q054.hhaw42sys2
	  section.data(3).logicalSrcIdx = 96;
	  section.data(3).dtTransOffset = 4;
	
	  ;% bkvdms3q054.et0f2t1sdh
	  section.data(4).logicalSrcIdx = 97;
	  section.data(4).dtTransOffset = 6;
	
	  ;% bkvdms3q054.krxtbpuo1n
	  section.data(5).logicalSrcIdx = 98;
	  section.data(5).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.n2gcigz0ph.lpwduy1bdl
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.n2gcigz0ph.fnc03qkdgbr.eghndihtil
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.n2gcigz0ph.fnc03qkdgbr.lcgwrzx4g0
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.n2gcigz0ph.fnc03qkdgbr.b4dbjrzg1o
	  section.data(1).logicalSrcIdx = 102;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.pvpaaioyj53.lpwduy1bdl
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.pvpaaioyj53.fnc03qkdgbr.eghndihtil
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.pvpaaioyj53.fnc03qkdgbr.lcgwrzx4g0
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.pvpaaioyj53.fnc03qkdgbr.b4dbjrzg1o
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.a4i0imrdpns.nwqykltl0h
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.a4i0imrdpns.fnc03qkdgbr.eghndihtil
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.a4i0imrdpns.fnc03qkdgbr.lcgwrzx4g0
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.a4i0imrdpns.fnc03qkdgbr.b4dbjrzg1o
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.m5sfktesnxt.lajpoqq15d
	  section.data(1).logicalSrcIdx = 111;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.m5sfktesnxt.fnc03qkdgbr.eghndihtil
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.m5sfktesnxt.fnc03qkdgbr.lcgwrzx4g0
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bkvdms3q054.m5sfktesnxt.fnc03qkdgbr.b4dbjrzg1o
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1659121441;
  targMap.checksum1 = 3099588852;
  targMap.checksum2 = 965696713;
  targMap.checksum3 = 2567926455;

