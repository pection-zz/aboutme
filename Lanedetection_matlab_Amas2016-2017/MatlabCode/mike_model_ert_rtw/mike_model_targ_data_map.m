  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
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
    ;% Auto data (idj0wfdbbnj)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% idj0wfdbbnj.Rotate_fillVal
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% idj0wfdbbnj.Startidxcrop_Value
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% idj0wfdbbnj.StartidxW_Value
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% idj0wfdbbnj.blurmatrix_Value
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% idj0wfdbbnj.sobelverticalmatrix_Value
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 27;
	
	  ;% idj0wfdbbnj.removeboundary_Value
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
    nTotSects     = 3;
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
    ;% Auto data (fkellqi4pow)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% fkellqi4pow.oelp5alfbp
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% fkellqi4pow.mryrolkm0f
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% fkellqi4pow.ecwc5k3scu
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% fkellqi4pow.fbsgzvozum
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% fkellqi4pow.ix1534vrru
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% fkellqi4pow.lfiveg1vrn
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% fkellqi4pow.iv0ar5xkqt
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% fkellqi4pow.nvid0aofmq
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% fkellqi4pow.jrvdhru2lz
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% fkellqi4pow.ed3k05d5vv
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% fkellqi4pow.eyway4yjtn
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 111309;
	
	  ;% fkellqi4pow.ahrpfav2ck
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 225585;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% fkellqi4pow.k55znbyyy5
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% fkellqi4pow.m24dcoghwx
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 921600;
	
	  ;% fkellqi4pow.cs23los3h1
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 1032900;
	
	  ;% fkellqi4pow.o012gx3ea4
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 1954500;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% fkellqi4pow.lvrlwfeznb
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    nTotSects     = 3;
    sectIdxOffset = 3;
    
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
    ;% Auto data (jdbfoob33pd)
    ;%
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% jdbfoob33pd.mzpou1vx3s
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jdbfoob33pd.jyj25urjtg
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% jdbfoob33pd.ewsi1h3p1n
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% jdbfoob33pd.amlz2mp1d2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% jdbfoob33pd.geqpitxgwa
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% jdbfoob33pd.nutm5mifcx
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% jdbfoob33pd.kyarto3iv1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% jdbfoob33pd.mahxiv5yhz
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 22;
	
	  ;% jdbfoob33pd.otl0d0gpga
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 32;
	
	  ;% jdbfoob33pd.olljidvtuq
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 34;
	
	  ;% jdbfoob33pd.bdgqf5ozed
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 36;
	
	  ;% jdbfoob33pd.dgnbldgdi0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 38;
	
	  ;% jdbfoob33pd.eqbbrk0fta
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 40;
	
	  ;% jdbfoob33pd.fcch3p5aef
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 42;
	
	  ;% jdbfoob33pd.itkqobekzx
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 44;
	
	  ;% jdbfoob33pd.lnqttqvcbp
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 46;
	
	  ;% jdbfoob33pd.dlbzsm4xse
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 48;
	
	  ;% jdbfoob33pd.egqdmm1ecm
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 50;
	
	  ;% jdbfoob33pd.fd52jcll4f
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 52;
	
	  ;% jdbfoob33pd.eglgt43lao
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 54;
	
	  ;% jdbfoob33pd.jsugc2cufo
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 64;
	
	  ;% jdbfoob33pd.lnciftc5s0
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 74;
	
	  ;% jdbfoob33pd.gmexbrfeug
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 76;
	
	  ;% jdbfoob33pd.bzlp5panju
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 78;
	
	  ;% jdbfoob33pd.egkq5bvnsp
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 80;
	
	  ;% jdbfoob33pd.nrzkqvsrtu
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 82;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% jdbfoob33pd.eklhns55w4
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% jdbfoob33pd.cfhlaarqmp
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jdbfoob33pd.az5edsbr22
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 1587227324;
  targMap.checksum1 = 3306777084;
  targMap.checksum2 = 3269658382;
  targMap.checksum3 = 2458256726;

