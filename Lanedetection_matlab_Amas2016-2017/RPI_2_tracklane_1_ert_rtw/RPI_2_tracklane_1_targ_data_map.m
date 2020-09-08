  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
    ;% Auto data (grdsk5w0biq)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% grdsk5w0biq.FindLocalMaxima_threshold
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% grdsk5w0biq.Rotate_fillVal
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% grdsk5w0biq.InsertText_textColor
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% grdsk5w0biq.InsertText_textOpacity
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% grdsk5w0biq.DrawShapes_lineWidth
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% grdsk5w0biq.DrawShapes1_lineWidth
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% grdsk5w0biq.DrawShapes3_lineWidth
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% grdsk5w0biq.InsertText_textLoc
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% grdsk5w0biq.Startidxcrop_Value
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% grdsk5w0biq.StartidxW_Value
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% grdsk5w0biq.blurmatrix_Value
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% grdsk5w0biq.sobelverticalmatrix_Value
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 27;
	
	  ;% grdsk5w0biq.removeboundary_Value
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 36;
	
	  ;% grdsk5w0biq.Saturation2_UpperSat
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 37;
	
	  ;% grdsk5w0biq.Saturation2_LowerSat
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 38;
	
	  ;% grdsk5w0biq.DrawShapes_RTP_FILLCOLOR
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 39;
	
	  ;% grdsk5w0biq.DrawShapes1_RTP_FILLCOLOR
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 42;
	
	  ;% grdsk5w0biq.Constant1_Value
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 45;
	
	  ;% grdsk5w0biq.Constant3_Value
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 47;
	
	  ;% grdsk5w0biq.Switch_Threshold
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 48;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% grdsk5w0biq.DrawShapes3_RTP_FILLCOLOR
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% grdsk5w0biq.DrawShapes2_RTP_FILLCOLOR
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 3;
	
	  ;% grdsk5w0biq.DrawShapes2_RTP_OPACITY
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    nTotSects     = 8;
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
    ;% Auto data (pto42looywn)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% pto42looywn.otmzqc2glp
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pto42looywn.onlvemolhe
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 70761;
	
	  ;% pto42looywn.gz424h505p
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 347601;
	
	  ;% pto42looywn.n32z2xig20
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 423842;
	
	  ;% pto42looywn.pbbgmy4yk5
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 502331;
	
	  ;% pto42looywn.e1w04c2mxy
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 581956;
	
	  ;% pto42looywn.auz2sk0vco
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 652717;
	
	  ;% pto42looywn.gtvh0gwvwe
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 723478;
	
	  ;% pto42looywn.fj4omn5ejb
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 794239;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% pto42looywn.fvav1ecztl
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pto42looywn.hdakiwvldc
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 933120;
	
	  ;% pto42looywn.esxp31bijp
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 1866240;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pto42looywn.amotfa3lag
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pto42looywn.obpaf3wtkb
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 360;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% pto42looywn.ixjnj5gel0
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pto42looywn.g4bmzjeuha
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 76241;
	
	  ;% pto42looywn.kzcjwsesnp
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 1009361;
	
	  ;% pto42looywn.onvcfdurro
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 1942481;
	
	  ;% pto42looywn.ckdj3tddue
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 2875601;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pto42looywn.l0l3rqlx4i
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pto42looywn.goifk2difl
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% pto42looywn.m5hwyrsvhx
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pto42looywn.dxgbpfjq05
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pto42looywn.ossn34u1gb
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 70761;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pto42looywn.ftsgxjwo3i
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pto42looywn.oed2agb4in
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
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
    nTotSects     = 9;
    sectIdxOffset = 8;
    
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
    ;% Auto data (jmorhhbqtzx)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.hfc3uypj41
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.iyvwtbiqxc
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.pn2mdau5de
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jmorhhbqtzx.mdu1womdzd
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 5;
	
	  ;% jmorhhbqtzx.odzmuxigza
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.kn5vtw0au3.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.p03modhhlz
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 54;
      section.data(54)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.em3djm2bnq
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jmorhhbqtzx.haoyorbhit
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 2;
	
	  ;% jmorhhbqtzx.nm1bnh4tsi
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 4;
	
	  ;% jmorhhbqtzx.nuqoi4ioq0
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 6;
	
	  ;% jmorhhbqtzx.pvp1fri5qe
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 8;
	
	  ;% jmorhhbqtzx.afz144l4ow
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 10;
	
	  ;% jmorhhbqtzx.mhqdxucqdq
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 12;
	
	  ;% jmorhhbqtzx.h0oyqkxl2d
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 22;
	
	  ;% jmorhhbqtzx.oebo0rmph5
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 32;
	
	  ;% jmorhhbqtzx.cn2kn3uzad
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 34;
	
	  ;% jmorhhbqtzx.en1cdxdx4k
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 36;
	
	  ;% jmorhhbqtzx.hvuzjoeziy
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 38;
	
	  ;% jmorhhbqtzx.byxz1ycoe5
	  section.data(13).logicalSrcIdx = 19;
	  section.data(13).dtTransOffset = 40;
	
	  ;% jmorhhbqtzx.jcq3gqi5tu
	  section.data(14).logicalSrcIdx = 20;
	  section.data(14).dtTransOffset = 42;
	
	  ;% jmorhhbqtzx.ili1c0xh1p
	  section.data(15).logicalSrcIdx = 21;
	  section.data(15).dtTransOffset = 44;
	
	  ;% jmorhhbqtzx.bhj5h1f45p
	  section.data(16).logicalSrcIdx = 22;
	  section.data(16).dtTransOffset = 46;
	
	  ;% jmorhhbqtzx.dkers22n3e
	  section.data(17).logicalSrcIdx = 23;
	  section.data(17).dtTransOffset = 48;
	
	  ;% jmorhhbqtzx.eo1njfgtqb
	  section.data(18).logicalSrcIdx = 24;
	  section.data(18).dtTransOffset = 50;
	
	  ;% jmorhhbqtzx.ngvj3o5ozq
	  section.data(19).logicalSrcIdx = 25;
	  section.data(19).dtTransOffset = 52;
	
	  ;% jmorhhbqtzx.oikfwmcbib
	  section.data(20).logicalSrcIdx = 26;
	  section.data(20).dtTransOffset = 54;
	
	  ;% jmorhhbqtzx.kjpw54usuj
	  section.data(21).logicalSrcIdx = 27;
	  section.data(21).dtTransOffset = 64;
	
	  ;% jmorhhbqtzx.kgcvzzngb0
	  section.data(22).logicalSrcIdx = 28;
	  section.data(22).dtTransOffset = 74;
	
	  ;% jmorhhbqtzx.ceyzwhcbsw
	  section.data(23).logicalSrcIdx = 29;
	  section.data(23).dtTransOffset = 76;
	
	  ;% jmorhhbqtzx.poezvqg5kd
	  section.data(24).logicalSrcIdx = 30;
	  section.data(24).dtTransOffset = 78;
	
	  ;% jmorhhbqtzx.fzh0rxy5mm
	  section.data(25).logicalSrcIdx = 31;
	  section.data(25).dtTransOffset = 80;
	
	  ;% jmorhhbqtzx.aslawa51pa
	  section.data(26).logicalSrcIdx = 32;
	  section.data(26).dtTransOffset = 82;
	
	  ;% jmorhhbqtzx.a3nl4rakmt
	  section.data(27).logicalSrcIdx = 33;
	  section.data(27).dtTransOffset = 84;
	
	  ;% jmorhhbqtzx.lxyps50d3n
	  section.data(28).logicalSrcIdx = 34;
	  section.data(28).dtTransOffset = 85;
	
	  ;% jmorhhbqtzx.h2za4opese
	  section.data(29).logicalSrcIdx = 35;
	  section.data(29).dtTransOffset = 86;
	
	  ;% jmorhhbqtzx.bnb3vdkaqg
	  section.data(30).logicalSrcIdx = 36;
	  section.data(30).dtTransOffset = 87;
	
	  ;% jmorhhbqtzx.avrq1yaor4
	  section.data(31).logicalSrcIdx = 37;
	  section.data(31).dtTransOffset = 93;
	
	  ;% jmorhhbqtzx.pwe3svytva
	  section.data(32).logicalSrcIdx = 38;
	  section.data(32).dtTransOffset = 99;
	
	  ;% jmorhhbqtzx.a4mqjg34id
	  section.data(33).logicalSrcIdx = 39;
	  section.data(33).dtTransOffset = 105;
	
	  ;% jmorhhbqtzx.dnf3uzgkxh
	  section.data(34).logicalSrcIdx = 40;
	  section.data(34).dtTransOffset = 111;
	
	  ;% jmorhhbqtzx.pffoh0tpuo
	  section.data(35).logicalSrcIdx = 41;
	  section.data(35).dtTransOffset = 117;
	
	  ;% jmorhhbqtzx.f20hmxlyfs
	  section.data(36).logicalSrcIdx = 42;
	  section.data(36).dtTransOffset = 123;
	
	  ;% jmorhhbqtzx.chiktuqd42
	  section.data(37).logicalSrcIdx = 43;
	  section.data(37).dtTransOffset = 129;
	
	  ;% jmorhhbqtzx.kn3fgwkqup
	  section.data(38).logicalSrcIdx = 44;
	  section.data(38).dtTransOffset = 135;
	
	  ;% jmorhhbqtzx.mj43n4xnxw
	  section.data(39).logicalSrcIdx = 45;
	  section.data(39).dtTransOffset = 141;
	
	  ;% jmorhhbqtzx.pfoupb4mcc
	  section.data(40).logicalSrcIdx = 46;
	  section.data(40).dtTransOffset = 147;
	
	  ;% jmorhhbqtzx.c0lj2bx3c2
	  section.data(41).logicalSrcIdx = 47;
	  section.data(41).dtTransOffset = 153;
	
	  ;% jmorhhbqtzx.mq4omvgb3n
	  section.data(42).logicalSrcIdx = 48;
	  section.data(42).dtTransOffset = 159;
	
	  ;% jmorhhbqtzx.ifmlijpve2
	  section.data(43).logicalSrcIdx = 49;
	  section.data(43).dtTransOffset = 165;
	
	  ;% jmorhhbqtzx.mxgpgw44xc
	  section.data(44).logicalSrcIdx = 50;
	  section.data(44).dtTransOffset = 171;
	
	  ;% jmorhhbqtzx.mldvlaspeu
	  section.data(45).logicalSrcIdx = 51;
	  section.data(45).dtTransOffset = 177;
	
	  ;% jmorhhbqtzx.in3yipozzc
	  section.data(46).logicalSrcIdx = 52;
	  section.data(46).dtTransOffset = 183;
	
	  ;% jmorhhbqtzx.iq3njuzs4t
	  section.data(47).logicalSrcIdx = 53;
	  section.data(47).dtTransOffset = 189;
	
	  ;% jmorhhbqtzx.eie3iek0nk
	  section.data(48).logicalSrcIdx = 54;
	  section.data(48).dtTransOffset = 195;
	
	  ;% jmorhhbqtzx.jomz5dcs2z
	  section.data(49).logicalSrcIdx = 55;
	  section.data(49).dtTransOffset = 196;
	
	  ;% jmorhhbqtzx.div1s5cw5y
	  section.data(50).logicalSrcIdx = 56;
	  section.data(50).dtTransOffset = 197;
	
	  ;% jmorhhbqtzx.fc1gaidbtx
	  section.data(51).logicalSrcIdx = 57;
	  section.data(51).dtTransOffset = 198;
	
	  ;% jmorhhbqtzx.fz4bwdldlk
	  section.data(52).logicalSrcIdx = 58;
	  section.data(52).dtTransOffset = 199;
	
	  ;% jmorhhbqtzx.cywme2hjtp
	  section.data(53).logicalSrcIdx = 59;
	  section.data(53).dtTransOffset = 200;
	
	  ;% jmorhhbqtzx.jlcwjsdvdo
	  section.data(54).logicalSrcIdx = 60;
	  section.data(54).dtTransOffset = 204;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.cljx1a4pyx
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.chbz4dudzz
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jmorhhbqtzx.l043aneyk2
	  section.data(2).logicalSrcIdx = 63;
	  section.data(2).dtTransOffset = 1;
	
	  ;% jmorhhbqtzx.egondhpzx2
	  section.data(3).logicalSrcIdx = 64;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% jmorhhbqtzx.kimmfq5qpy
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jmorhhbqtzx.ii5auqxx55
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
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


  targMap.checksum0 = 1084031360;
  targMap.checksum1 = 1285645819;
  targMap.checksum2 = 2769968102;
  targMap.checksum3 = 487796315;

