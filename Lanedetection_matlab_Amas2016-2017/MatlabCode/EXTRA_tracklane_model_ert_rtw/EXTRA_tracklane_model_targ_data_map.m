  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (o2gtshlekae)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% o2gtshlekae.FindLocalMaxima_threshold
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% o2gtshlekae.InsertText_textColor
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% o2gtshlekae.InsertText_textOpacity
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% o2gtshlekae.DrawShapes_lineWidth
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% o2gtshlekae.DrawShapes1_lineWidth
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% o2gtshlekae.DrawShapes3_lineWidth
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% o2gtshlekae.InsertText_textLoc
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% o2gtshlekae.Rotate_fillVal
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% o2gtshlekae.Startidxcrop_Value
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% o2gtshlekae.StartidxW_Value
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% o2gtshlekae.blurmatrix_Value
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% o2gtshlekae.sobelverticalmatrix_Value
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 27;
	
	  ;% o2gtshlekae.removeboundary_Value
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 36;
	
	  ;% o2gtshlekae.Saturation2_UpperSat
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 37;
	
	  ;% o2gtshlekae.Saturation2_LowerSat
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 38;
	
	  ;% o2gtshlekae.Constant3_Value
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 39;
	
	  ;% o2gtshlekae.Constant1_Value
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 40;
	
	  ;% o2gtshlekae.DrawShapes_RTP_FILLCOLOR
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 41;
	
	  ;% o2gtshlekae.DrawShapes1_RTP_FILLCOLOR
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 44;
	
	  ;% o2gtshlekae.Constant1_Value_amvyq0ozrf
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 47;
	
	  ;% o2gtshlekae.Switch_Threshold
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 49;
	
	  ;% o2gtshlekae.Constant_Value
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 50;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% o2gtshlekae.DrawShapes3_RTP_FILLCOLOR
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% o2gtshlekae.DrawShapes2_RTP_FILLCOLOR
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 3;
	
	  ;% o2gtshlekae.DrawShapes2_RTP_OPACITY
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (p5mwgo545sp)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% p5mwgo545sp.bi4skneon2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% p5mwgo545sp.mzcf0l2aai
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 7500;
	
	  ;% p5mwgo545sp.frptfpgruj
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 120900;
	
	  ;% p5mwgo545sp.o3zmx1yzu1
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 131396;
	
	  ;% p5mwgo545sp.lnjtlblvks
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 142352;
	
	  ;% p5mwgo545sp.bm2pd5wx1c
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 149852;
	
	  ;% p5mwgo545sp.ghgh0vu4n0
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 157352;
	
	  ;% p5mwgo545sp.pzid2z1ypa
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 164852;
	
	  ;% p5mwgo545sp.o2nhzu4y5q
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 222452;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% p5mwgo545sp.o43uvavthw
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% p5mwgo545sp.jr153jryd4
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 57600;
	
	  ;% p5mwgo545sp.apto34umvz
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 115200;
	
	  ;% p5mwgo545sp.kvk4jty3ym
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 172800;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% p5mwgo545sp.jbpqo0i4sy
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% p5mwgo545sp.nzbdgfjyg4
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 19200;
	
	  ;% p5mwgo545sp.ph0vo32izp
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 38400;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% p5mwgo545sp.k1o3klaip5
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% p5mwgo545sp.enpvi4ksq1
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 360;
	
	  ;% p5mwgo545sp.f0ltwrzciw
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 675;
	
	  ;% p5mwgo545sp.albcborj0a
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 677;
	
	  ;% p5mwgo545sp.mi4dmcyuet
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 678;
	
	  ;% p5mwgo545sp.jqcqqrrbkt
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 679;
	
	  ;% p5mwgo545sp.f5rac5iyy0
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 680;
	
	  ;% p5mwgo545sp.icnd25ntfa
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 681;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% p5mwgo545sp.ju2v5jfo5h
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% p5mwgo545sp.ksdx5xp0oh
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% p5mwgo545sp.mj1cwespvp
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% p5mwgo545sp.ivbsoweeiz
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 57600;
	
	  ;% p5mwgo545sp.jugtc1cr4n
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 76800;
	
	  ;% p5mwgo545sp.pocv0dx4yl
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 96000;
	
	  ;% p5mwgo545sp.b25gvutpwi
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 105600;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% p5mwgo545sp.koxfjrqjjm
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% p5mwgo545sp.llndukaqb5
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 7500;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
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
    nTotSects     = 8;
    sectIdxOffset = 7;
    
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
    ;% Auto data (hbc41ttwksq)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% hbc41ttwksq.pzlu1hhtiy
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% hbc41ttwksq.go1gjazlrb
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% hbc41ttwksq.npghbfxqah.LoggedData
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% hbc41ttwksq.al4siilupa.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 2;
	
	  ;% hbc41ttwksq.lr5ucmfayd
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% hbc41ttwksq.asvucysmpb
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 54;
      section.data(54)  = dumData; %prealloc
      
	  ;% hbc41ttwksq.kyxstdtkap
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% hbc41ttwksq.egmzukvmmk
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 2;
	
	  ;% hbc41ttwksq.hrvvk5wod5
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 4;
	
	  ;% hbc41ttwksq.mufqyl4at5
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 6;
	
	  ;% hbc41ttwksq.mp3cfqacrp
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 8;
	
	  ;% hbc41ttwksq.jdgs3wtwbk
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 10;
	
	  ;% hbc41ttwksq.ho1ly20dmp
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 12;
	
	  ;% hbc41ttwksq.pdkoedolqt
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 22;
	
	  ;% hbc41ttwksq.lgzopfpjul
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 32;
	
	  ;% hbc41ttwksq.fvcrjuzbuv
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 34;
	
	  ;% hbc41ttwksq.o5dgk2f5yz
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 36;
	
	  ;% hbc41ttwksq.drcfm3ewtn
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 38;
	
	  ;% hbc41ttwksq.beuigqd3f5
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 40;
	
	  ;% hbc41ttwksq.hfr4c5y4lt
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 42;
	
	  ;% hbc41ttwksq.n3z2g3e1jo
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 44;
	
	  ;% hbc41ttwksq.mkzkryxx2r
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 46;
	
	  ;% hbc41ttwksq.pesc4csj2s
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 48;
	
	  ;% hbc41ttwksq.e043dvgw1z
	  section.data(18).logicalSrcIdx = 23;
	  section.data(18).dtTransOffset = 50;
	
	  ;% hbc41ttwksq.hy2upfuklw
	  section.data(19).logicalSrcIdx = 24;
	  section.data(19).dtTransOffset = 52;
	
	  ;% hbc41ttwksq.ma0ldioyg2
	  section.data(20).logicalSrcIdx = 25;
	  section.data(20).dtTransOffset = 54;
	
	  ;% hbc41ttwksq.ikbsbj2mu4
	  section.data(21).logicalSrcIdx = 26;
	  section.data(21).dtTransOffset = 64;
	
	  ;% hbc41ttwksq.flblnchd3d
	  section.data(22).logicalSrcIdx = 27;
	  section.data(22).dtTransOffset = 74;
	
	  ;% hbc41ttwksq.egqssuzumj
	  section.data(23).logicalSrcIdx = 28;
	  section.data(23).dtTransOffset = 76;
	
	  ;% hbc41ttwksq.nrfyed4wkl
	  section.data(24).logicalSrcIdx = 29;
	  section.data(24).dtTransOffset = 78;
	
	  ;% hbc41ttwksq.kt4tojq2jk
	  section.data(25).logicalSrcIdx = 30;
	  section.data(25).dtTransOffset = 80;
	
	  ;% hbc41ttwksq.kqjbwcdiup
	  section.data(26).logicalSrcIdx = 31;
	  section.data(26).dtTransOffset = 82;
	
	  ;% hbc41ttwksq.jpjo2hpvzz
	  section.data(27).logicalSrcIdx = 32;
	  section.data(27).dtTransOffset = 84;
	
	  ;% hbc41ttwksq.kd5da2gvs4
	  section.data(28).logicalSrcIdx = 33;
	  section.data(28).dtTransOffset = 85;
	
	  ;% hbc41ttwksq.dozdrdxn2c
	  section.data(29).logicalSrcIdx = 34;
	  section.data(29).dtTransOffset = 86;
	
	  ;% hbc41ttwksq.fdoln1kz1t
	  section.data(30).logicalSrcIdx = 35;
	  section.data(30).dtTransOffset = 87;
	
	  ;% hbc41ttwksq.mh2vlgaj3a
	  section.data(31).logicalSrcIdx = 36;
	  section.data(31).dtTransOffset = 93;
	
	  ;% hbc41ttwksq.l3yrop3fnf
	  section.data(32).logicalSrcIdx = 37;
	  section.data(32).dtTransOffset = 99;
	
	  ;% hbc41ttwksq.fp4mverxgl
	  section.data(33).logicalSrcIdx = 38;
	  section.data(33).dtTransOffset = 105;
	
	  ;% hbc41ttwksq.n3eud2ydzm
	  section.data(34).logicalSrcIdx = 39;
	  section.data(34).dtTransOffset = 111;
	
	  ;% hbc41ttwksq.gvh0ffbh5d
	  section.data(35).logicalSrcIdx = 40;
	  section.data(35).dtTransOffset = 117;
	
	  ;% hbc41ttwksq.hzvrwmzehi
	  section.data(36).logicalSrcIdx = 41;
	  section.data(36).dtTransOffset = 123;
	
	  ;% hbc41ttwksq.a0nfbgrvkv
	  section.data(37).logicalSrcIdx = 42;
	  section.data(37).dtTransOffset = 129;
	
	  ;% hbc41ttwksq.mz3sdfldxd
	  section.data(38).logicalSrcIdx = 43;
	  section.data(38).dtTransOffset = 135;
	
	  ;% hbc41ttwksq.ctbzzsjjtq
	  section.data(39).logicalSrcIdx = 44;
	  section.data(39).dtTransOffset = 141;
	
	  ;% hbc41ttwksq.pjsmwzetaj
	  section.data(40).logicalSrcIdx = 45;
	  section.data(40).dtTransOffset = 147;
	
	  ;% hbc41ttwksq.eeib524o0k
	  section.data(41).logicalSrcIdx = 46;
	  section.data(41).dtTransOffset = 153;
	
	  ;% hbc41ttwksq.mmw2wqqzch
	  section.data(42).logicalSrcIdx = 47;
	  section.data(42).dtTransOffset = 159;
	
	  ;% hbc41ttwksq.pgrpuvraid
	  section.data(43).logicalSrcIdx = 48;
	  section.data(43).dtTransOffset = 165;
	
	  ;% hbc41ttwksq.kt4ydietsy
	  section.data(44).logicalSrcIdx = 49;
	  section.data(44).dtTransOffset = 171;
	
	  ;% hbc41ttwksq.a5gjsugug3
	  section.data(45).logicalSrcIdx = 50;
	  section.data(45).dtTransOffset = 177;
	
	  ;% hbc41ttwksq.pnu2dsgq32
	  section.data(46).logicalSrcIdx = 51;
	  section.data(46).dtTransOffset = 183;
	
	  ;% hbc41ttwksq.lysxv1joq2
	  section.data(47).logicalSrcIdx = 52;
	  section.data(47).dtTransOffset = 189;
	
	  ;% hbc41ttwksq.nm5rf0pxlv
	  section.data(48).logicalSrcIdx = 53;
	  section.data(48).dtTransOffset = 195;
	
	  ;% hbc41ttwksq.lspm3lc32s
	  section.data(49).logicalSrcIdx = 54;
	  section.data(49).dtTransOffset = 196;
	
	  ;% hbc41ttwksq.i4kswklwbn
	  section.data(50).logicalSrcIdx = 55;
	  section.data(50).dtTransOffset = 197;
	
	  ;% hbc41ttwksq.c0eon145uo
	  section.data(51).logicalSrcIdx = 56;
	  section.data(51).dtTransOffset = 198;
	
	  ;% hbc41ttwksq.iq4bl30okm
	  section.data(52).logicalSrcIdx = 57;
	  section.data(52).dtTransOffset = 199;
	
	  ;% hbc41ttwksq.njkpu5icv1
	  section.data(53).logicalSrcIdx = 58;
	  section.data(53).dtTransOffset = 200;
	
	  ;% hbc41ttwksq.ir2zhtporr
	  section.data(54).logicalSrcIdx = 59;
	  section.data(54).dtTransOffset = 204;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% hbc41ttwksq.pmez4r4nfv
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% hbc41ttwksq.o1erccympx
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% hbc41ttwksq.kfpld50vkw
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 57600;
	
	  ;% hbc41ttwksq.d33fnb2sbb
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 57601;
	
	  ;% hbc41ttwksq.agqmrpd5xm
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 57602;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% hbc41ttwksq.pk02gilddo
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% hbc41ttwksq.g33053fg2o
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 2;
	
	  ;% hbc41ttwksq.jko3mvse12
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
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


  targMap.checksum0 = 1078325312;
  targMap.checksum1 = 645338019;
  targMap.checksum2 = 3643901027;
  targMap.checksum3 = 2251212523;

