xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 116;
 -20.55852;-2.30188;-3.18428;,
 -23.58942;-1.51843;-2.29535;,
 -24.64992;0.72147;-3.18428;,
 -20.55852;0.72147;-4.32599;,
 -23.58942;2.96134;-2.29535;,
 -20.55852;3.74570;-3.18428;,
 -24.64992;3.74570;0.24169;,
 -20.55852;4.75342;0.24169;,
 -23.58942;2.96134;2.77957;,
 -20.55852;3.74570;3.66767;,
 -24.64992;0.72147;3.66767;,
 -20.55852;0.72147;4.80938;,
 -23.58942;-1.51843;2.77957;,
 -20.55852;-2.30188;3.66767;,
 -24.64992;-2.30188;0.24169;,
 -20.55852;-3.30974;0.24169;,
 -23.58942;-1.51843;-2.29535;,
 -20.55852;-2.30188;-3.18428;,
 -24.64992;-2.30188;0.24169;,
 -26.01346;0.72147;0.24169;,
 -23.58942;-1.51843;2.77957;,
 -24.64992;0.72147;3.66767;,
 -23.58942;2.96134;2.77957;,
 -24.64992;3.74570;0.24169;,
 -17.18276;4.68476;-7.35019;,
 -17.96541;8.14766;-5.43423;,
 -10.71502;11.64223;-7.35019;,
 -10.21448;5.94791;-9.81274;,
 -4.49335;10.95247;-5.43423;,
 -1.72445;3.97579;-7.35019;,
 -0.96861;-0.58265;-7.80805;,
 1.02604;4.21686;0.03913;,
 -1.21387;-1.83986;0.03913;,
 -2.46189;12.36707;0.03913;,
 -4.49335;10.95247;5.51249;,
 -1.72445;3.97579;7.42846;,
 -0.96861;-0.58265;6.26917;,
 -10.71502;11.64223;7.42846;,
 -10.21448;5.94791;9.89184;,
 -17.40457;8.19696;5.51249;,
 -17.18276;4.68476;7.42846;,
 -17.59794;9.41571;0.03913;,
 -10.85314;13.21918;0.03913;,
 -17.40457;8.19696;5.51249;,
 -10.71502;11.64223;7.42846;,
 -4.49335;10.95247;5.51249;,
 -2.46189;12.36707;0.03913;,
 -11.52191;-4.23207;3.56220;,
 -16.63452;-3.96596;3.73714;,
 -16.83038;-4.86574;-0.12242;,
 -11.71778;-5.13190;-0.29736;,
 -11.85003;4.10056;4.34566;,
 -12.02413;6.13196;0.21826;,
 -17.16770;6.18138;0.38315;,
 -16.98273;3.95073;4.50135;,
 -12.02413;6.13117;0.23081;,
 -11.99902;4.70995;-4.05982;,
 -17.13170;4.56008;-3.90413;,
 -17.16770;6.18060;0.39654;,
 -6.50725;-4.82554;-0.44886;,
 -6.44783;-3.92323;3.41572;,
 -6.76086;4.65967;3.69696;,
 -6.86215;5.89597;0.04332;,
 -6.86215;5.89514;0.05671;,
 -6.89231;5.19457;-3.68734;,
 -16.77011;-3.41261;-3.88320;,
 -11.65669;-3.67967;-4.05814;,
 -6.58342;-3.37080;-4.20462;,
 -22.21500;4.80950;0.48108;,
 -22.14803;4.20349;4.12301;,
 -22.00155;-3.56584;0.10023;,
 -21.94215;-2.66348;3.96397;,
 -22.07775;-2.11104;-3.65637;,
 -22.27694;4.73331;-3.17842;,
 -22.21500;4.80869;0.49448;,
 -1.53193;-1.71179;-3.38684;,
 -1.44153;-3.55914;-0.55181;,
 -1.42898;-2.13365;2.43472;,
 -1.61982;4.67558;3.38977;,
 -1.68511;5.27411;-0.14920;,
 -1.68511;5.27323;-0.13581;,
 -1.74538;5.19036;-3.70576;,
 -6.52567;0.63605;5.97704;,
 -1.40974;0.81690;4.92070;,
 -11.65835;0.51972;6.13440;,
 -16.79105;0.40337;6.29176;,
 -21.93043;0.31632;6.04149;,
 -17.00866;1.29567;-6.01345;,
 -22.13380;1.14998;-5.44845;,
 -11.87682;1.41205;-6.17081;,
 -6.74413;1.52835;-6.32818;,
 -1.59554;1.57935;-5.58824;,
 -11.65835;0.51972;6.13440;,
 -6.52567;0.63605;5.97704;,
 -6.76086;4.65967;3.69696;,
 -11.85003;4.10056;4.34566;,
 -21.93043;0.31632;6.04149;,
 -16.79105;0.40337;6.29176;,
 -16.98273;3.95073;4.50135;,
 -22.14803;4.20349;4.12301;,
 -6.52567;0.63605;5.97704;,
 -1.40974;0.81690;4.92070;,
 -1.61982;4.67558;3.38977;,
 -6.76086;4.65967;3.69696;,
 -11.87682;1.41205;-6.17081;,
 -17.00866;1.29567;-6.01345;,
 -17.13170;4.56008;-3.90413;,
 -11.99902;4.70995;-4.05982;,
 -6.74413;1.52835;-6.32818;,
 -11.87682;1.41205;-6.17081;,
 -11.99902;4.70995;-4.05982;,
 -6.89231;5.19457;-3.68734;,
 -17.00866;1.29567;-6.01345;,
 -22.13380;1.14998;-5.44845;,
 -22.27694;4.73331;-3.17842;,
 -17.13170;4.56008;-3.90413;;
 
 56;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;9,8,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;1,18,19,2;,
 4;18,20,21,19;,
 4;19,21,22,23;,
 4;2,19,23,4;,
 4;24,25,26,27;,
 4;27,26,28,29;,
 4;30,29,31,32;,
 4;29,28,33,31;,
 4;31,33,34,35;,
 4;32,31,35,36;,
 4;35,34,37,38;,
 4;38,37,39,40;,
 4;25,41,42,26;,
 4;41,43,44,42;,
 4;42,44,45,46;,
 4;26,42,46,28;,
 4;47,48,49,50;,
 4;51,52,53,54;,
 4;55,56,57,58;,
 4;50,59,60,47;,
 4;61,62,52,51;,
 4;63,64,56,55;,
 4;65,66,50,49;,
 4;66,67,59,50;,
 4;54,53,68,69;,
 4;70,49,48,71;,
 4;72,65,49,70;,
 4;58,57,73,74;,
 4;67,75,76,59;,
 4;77,60,59,76;,
 4;78,79,62,61;,
 4;80,81,64,63;,
 4;82,60,77,83;,
 4;47,60,82,84;,
 4;85,48,47,84;,
 4;71,48,85,86;,
 4;87,65,72,88;,
 4;89,66,65,87;,
 4;90,67,66,89;,
 4;91,75,67,90;,
 4;85,84,51,54;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;91,90,64,81;;
 
 MeshMaterialList {
  18;
  56;
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  86;
  -0.504098;-0.639639;-0.580299;,
  -0.504137;0.639564;-0.580347;,
  -0.504133;0.639548;0.580369;,
  -0.504094;-0.639623;0.580320;,
  -0.659034;-0.000028;0.752113;,
  -0.302860;-0.703141;0.643326;,
  -0.625474;-0.780245;-0.000030;,
  -0.302914;-0.703161;-0.643279;,
  -0.659061;-0.000028;-0.752090;,
  -0.302981;0.703085;-0.643330;,
  -0.625543;0.780190;-0.000030;,
  -0.302928;0.703066;0.643377;,
  -0.318208;-0.000024;-0.948021;,
  -0.283749;0.958899;-0.000027;,
  -0.318087;-0.000023;0.948061;,
  -0.283634;-0.958933;-0.000027;,
  -0.879708;-0.475514;-0.000029;,
  -0.472877;0.672567;-0.569246;,
  0.986226;-0.089858;-0.138866;,
  0.495384;0.662772;-0.561540;,
  0.969292;-0.145374;0.198342;,
  0.495392;0.662787;0.561516;,
  -0.479104;0.671204;0.565636;,
  0.992390;-0.119376;0.030183;,
  -0.124669;0.762792;0.634512;,
  -0.391837;0.379397;0.838166;,
  -0.488621;0.872450;0.009036;,
  -0.384312;0.357261;-0.851275;,
  -0.119019;0.762676;-0.635735;,
  0.625248;0.417254;-0.659518;,
  0.585068;0.810984;-0.000000;,
  0.807007;0.239281;0.539892;,
  -0.032444;0.397347;-0.917095;,
  0.988642;0.149416;0.016145;,
  -0.036501;0.409831;0.911431;,
  -0.187233;0.982304;0.004795;,
  0.196964;-0.466129;-0.862513;,
  0.253333;-0.550870;0.795214;,
  -0.123767;0.048852;-0.991108;,
  -0.061134;-0.054567;0.996637;,
  -0.029292;0.088418;-0.995653;,
  0.034044;-0.014359;0.999317;,
  0.320399;-0.944609;-0.071120;,
  -0.243093;-0.967929;-0.063402;,
  0.001658;-0.997543;-0.070041;,
  -0.019765;-0.038656;0.999057;,
  -0.149441;-0.986536;-0.066443;,
  -0.082881;0.064414;-0.994476;,
  0.089909;-0.124500;-0.988138;,
  0.188588;-0.979436;-0.071694;,
  0.152506;-0.224563;0.962452;,
  0.295761;-0.759618;0.579229;,
  0.182059;-0.783031;0.594741;,
  0.024495;-0.798008;0.602149;,
  -0.083158;-0.802686;0.590576;,
  -0.153455;-0.802233;0.576953;,
  0.250426;-0.688070;-0.681063;,
  -0.188132;-0.725034;-0.662520;,
  -0.120738;-0.724445;-0.678676;,
  -0.016790;-0.719704;-0.694078;,
  0.137690;-0.707710;-0.692956;,
  0.016876;0.722463;0.691204;,
  0.005764;0.907152;0.420764;,
  -0.060850;0.916827;0.394621;,
  -0.040879;0.725586;0.686917;,
  0.059617;0.757509;0.650097;,
  0.038273;0.948858;0.313376;,
  -0.126591;0.936593;0.326754;,
  -0.094078;0.745608;0.659711;,
  0.070245;0.967530;0.242797;,
  0.097774;0.772771;0.627109;,
  -0.017013;0.956236;-0.292101;,
  -0.024140;0.800614;-0.598694;,
  -0.082515;0.802081;-0.591488;,
  -0.082066;0.961537;-0.262131;,
  0.020923;0.983886;-0.177568;,
  0.021372;0.832045;-0.554297;,
  -0.134748;0.818233;-0.558873;,
  -0.143556;0.971588;-0.188173;,
  0.055890;0.993012;-0.103938;,
  0.061042;0.845353;-0.530709;,
  -0.879731;0.475472;-0.000029;,
  0.036751;0.471399;0.881154;,
  0.107080;0.433979;0.894537;,
  -0.017162;0.561491;-0.827305;,
  0.053744;0.525274;-0.849234;;
  56;
  4;7,0,8,12;,
  4;12,8,1,9;,
  4;9,1,10,13;,
  4;13,10,2,11;,
  4;11,2,4,14;,
  4;14,4,3,5;,
  4;5,3,6,15;,
  4;15,6,0,7;,
  4;0,6,16,8;,
  4;6,3,4,16;,
  4;81,4,2,10;,
  4;8,81,10,1;,
  4;27,17,28,32;,
  4;32,28,19,29;,
  4;18,18,33,23;,
  4;29,19,30,33;,
  4;33,30,21,31;,
  4;23,33,31,20;,
  4;31,21,24,34;,
  4;34,24,22,25;,
  4;17,26,35,28;,
  4;26,22,24,35;,
  4;35,24,21,30;,
  4;28,35,30,19;,
  4;53,54,46,44;,
  4;61,62,63,64;,
  4;71,72,73,74;,
  4;44,49,52,53;,
  4;65,66,62,61;,
  4;75,76,72,71;,
  4;58,59,44,46;,
  4;59,60,49,44;,
  4;64,63,67,68;,
  4;43,46,54,55;,
  4;57,58,46,43;,
  4;74,73,77,78;,
  4;60,56,42,49;,
  4;51,52,49,42;,
  4;70,69,66,65;,
  4;79,80,76,75;,
  4;50,52,51,37;,
  4;53,52,50,41;,
  4;45,54,53,41;,
  4;55,54,45,39;,
  4;47,58,57,38;,
  4;40,59,58,47;,
  4;48,60,59,40;,
  4;36,56,60,48;,
  4;45,41,61,64;,
  4;41,82,65,61;,
  4;39,45,64,68;,
  4;50,83,70,65;,
  4;40,47,73,72;,
  4;84,40,72,76;,
  4;47,38,77,73;,
  4;85,48,76,80;;
 }
 MeshTextureCoords {
  116;
  0.500000;0.000000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.500000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.875000;,
  0.500000;0.875000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.500000;0.000000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.500000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.562500;0.125000;,
  0.562500;0.187500;,
  0.500000;0.187500;,
  0.500000;0.125000;,
  0.625000;0.125000;,
  0.875000;0.125000;,
  0.875000;0.187500;,
  0.625000;0.187500;,
  0.125000;0.125000;,
  0.375000;0.125000;,
  0.375000;0.187500;,
  0.125000;0.187500;,
  0.500000;0.062500;,
  0.562500;0.062500;,
  0.625000;0.062500;,
  0.875000;0.062500;,
  0.125000;0.062500;,
  0.375000;0.062500;,
  0.437500;0.187500;,
  0.437500;0.125000;,
  0.437500;0.062500;,
  0.875000;0.250000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.562500;0.250000;,
  0.437500;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.625000;0.062500;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.187500;,
  0.625000;0.250000;,
  0.375000;0.187500;,
  0.375000;0.250000;,
  0.375000;0.125000;,
  0.375000;0.062500;,
  0.375000;0.000000;,
  0.125000;0.187500;,
  0.125000;0.125000;,
  0.125000;0.125000;,
  0.125000;0.187500;,
  0.375000;0.062500;,
  0.375000;0.125000;,
  0.375000;0.125000;,
  0.375000;0.062500;,
  0.875000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.875000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.187500;,
  0.625000;0.187500;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.875000;0.000000;,
  0.625000;0.000000;;
 }
}
