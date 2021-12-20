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
 86;
 -204.23784;15.31049;16.73649;,
 -204.23784;0.81633;8.36842;,
 -30.59723;0.81633;8.36842;,
 -30.59723;15.31049;16.73649;,
 -204.23784;0.81633;-8.36808;,
 -30.59723;0.81633;-8.36808;,
 -204.23784;15.31049;-16.73649;,
 -30.59723;15.31049;-16.73649;,
 -204.23784;29.80515;-8.36842;,
 -30.59723;29.80515;-8.36842;,
 -204.23784;29.80515;8.36842;,
 -30.59723;29.80515;8.36842;,
 -204.23784;15.31049;16.73649;,
 -30.59723;15.31049;16.73649;,
 143.04349;15.31049;16.73649;,
 143.04349;7.22236;12.06687;,
 143.04349;0.81633;8.36842;,
 143.04349;0.81633;-8.36808;,
 143.04349;0.81633;0.03835;,
 143.04349;0.81633;0.76826;,
 143.04349;0.81633;6.27521;,
 143.04349;15.31049;-16.73649;,
 143.04349;21.66375;-13.06893;,
 143.04349;29.80515;-8.36842;,
 143.04349;29.80515;8.36842;,
 143.04349;29.80515;0.69802;,
 143.04349;15.31049;16.73649;,
 176.72974;14.97539;8.07252;,
 172.87831;11.41047;6.01409;,
 198.27808;14.22935;1.84074;,
 198.16533;15.20954;2.43730;,
 176.72974;8.48724;4.32656;,
 176.72974;8.56207;2.52332;,
 185.91032;10.60048;1.27320;,
 198.38496;13.29940;1.27540;,
 173.74196;8.82251;-3.74561;,
 176.72974;15.64592;-8.07252;,
 198.33931;15.40991;-2.39115;,
 201.01399;13.95381;-0.78336;,
 176.72974;18.10256;-6.65408;,
 176.72974;22.13390;-4.32656;,
 174.62079;21.95574;-0.03478;,
 204.40184;15.97322;-0.15643;,
 204.40184;15.98441;-0.42740;,
 204.40184;15.95133;0.37005;,
 176.72974;21.79863;3.74561;,
 204.40184;15.27774;0.79744;,
 198.16533;15.20954;2.43730;,
 173.72794;17.43932;6.51003;,
 -204.23784;0.81633;8.36842;,
 -204.23784;15.31049;16.73649;,
 -204.23784;15.31049;0.00000;,
 -204.23784;0.81633;-8.36808;,
 -204.23784;15.31049;-16.73649;,
 -204.23784;29.80515;-8.36842;,
 -204.23784;29.80515;8.36842;,
 204.40184;15.27774;0.79744;,
 204.40184;15.03071;0.65475;,
 204.40184;15.30302;0.18036;,
 204.40184;14.63673;0.42740;,
 204.40184;14.65981;-0.13031;,
 204.40184;15.07075;-0.13879;,
 204.40184;15.31049;0.00000;,
 204.40184;14.67016;-0.37005;,
 204.40184;15.34374;-0.79744;,
 204.40184;15.31676;-0.14337;,
 204.40184;15.73534;-0.57111;,
 204.40184;15.49101;-0.14693;,
 204.40184;15.98441;-0.42740;,
 204.40184;15.97322;-0.15643;,
 204.40184;15.54412;-0.14761;,
 204.40184;15.95133;0.37005;,
 204.40184;15.38277;0.04140;,
 175.68225;19.11091;-7.37806;,
 176.72974;14.97539;8.07252;,
 204.40184;14.65981;-0.13031;,
 195.36009;12.69860;-0.01340;,
 204.40184;14.67016;-0.37005;,
 204.40184;15.46183;-0.09603;,
 176.72974;8.65776;0.22736;,
 204.40184;15.03071;0.65475;,
 204.40184;15.27774;0.79744;,
 204.40184;14.63673;0.42740;,
 173.56854;8.61416;1.27184;,
 204.40184;15.34374;-0.79744;,
 204.40184;15.73534;-0.57111;;
 
 86;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 3;14,3,15;,
 3;15,3,16;,
 3;3,2,16;,
 3;17,18,5;,
 3;18,19,5;,
 3;19,20,5;,
 3;20,16,5;,
 3;16,2,5;,
 4;5,7,21,17;,
 3;21,7,22;,
 3;22,7,23;,
 3;7,9,23;,
 3;24,25,11;,
 3;25,23,11;,
 3;23,9,11;,
 4;11,13,26,24;,
 4;27,28,29,30;,
 4;31,32,33,34;,
 4;35,36,37,38;,
 3;36,39,37;,
 4;40,41,42,43;,
 3;44,45,46;,
 3;46,45,47;,
 3;45,48,47;,
 3;49,50,51;,
 3;52,49,51;,
 3;53,52,51;,
 3;54,53,51;,
 3;55,54,51;,
 3;50,55,51;,
 3;56,57,58;,
 4;59,60,61,62;,
 4;63,64,65,61;,
 4;64,66,67,65;,
 3;68,69,70;,
 4;71,56,58,72;,
 4;14,15,28,27;,
 4;16,20,32,31;,
 4;17,21,36,35;,
 3;21,22,36;,
 3;36,22,39;,
 3;22,73,39;,
 4;23,25,41,40;,
 3;45,24,48;,
 3;74,48,26;,
 3;48,24,26;,
 4;75,76,38,77;,
 4;42,41,45,44;,
 3;61,60,63;,
 3;61,65,62;,
 4;65,67,78,62;,
 3;69,71,70;,
 3;70,71,78;,
 3;71,72,78;,
 4;79,18,17,35;,
 4;41,25,24,45;,
 4;30,29,80,81;,
 3;75,82,76;,
 3;82,34,76;,
 3;34,33,76;,
 3;47,48,74;,
 4;83,19,18,79;,
 3;33,32,83;,
 4;38,37,84,77;,
 3;39,73,37;,
 3;73,85,37;,
 3;85,84,37;,
 4;32,20,19,83;,
 4;38,76,79,35;,
 4;76,33,83,79;,
 4;29,28,31,34;,
 4;58,57,59,62;,
 4;67,66,68,70;,
 3;72,58,62;,
 4;28,15,16,31;,
 4;73,22,23,40;,
 3;78,67,70;,
 3;78,72,62;,
 4;80,29,34,82;,
 4;85,73,40,43;;
 
 MeshMaterialList {
  3;
  86;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  2,
  2,
  2,
  2;;
  Material {
   0.376000;0.224000;0.040000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.144000;0.008000;1.000000;;
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
  72;
  0.000000;-0.499994;0.866029;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.500009;-0.866020;,
  0.000000;0.499981;-0.866036;,
  0.000000;1.000000;0.000000;,
  0.000000;-0.499994;0.866029;,
  0.000000;0.499981;-0.866037;,
  0.107510;-0.534829;0.838093;,
  0.070819;-0.468248;0.880754;,
  0.173419;-0.924807;-0.338612;,
  0.115935;-0.521987;-0.845038;,
  0.071059;0.527705;-0.846450;,
  0.116166;0.993014;-0.020713;,
  0.211316;0.523595;0.825345;,
  1.000000;0.000000;0.000000;,
  0.256090;0.881290;-0.397172;,
  0.236385;0.855011;0.461604;,
  -1.000000;0.000000;0.000000;,
  0.212298;-0.563890;0.798097;,
  0.216103;-0.975897;-0.030394;,
  0.235884;-0.825992;-0.511953;,
  0.213094;-0.551796;-0.806296;,
  0.251605;0.879720;-0.403470;,
  0.207419;0.473135;0.856224;,
  0.118574;-0.991945;0.044550;,
  0.114296;0.993419;0.007362;,
  0.200775;0.978924;0.037369;,
  0.216579;-0.974984;0.050001;,
  0.214051;0.976476;0.026009;,
  0.111032;-0.993707;0.014780;,
  0.219282;-0.526799;0.821217;,
  0.211304;-0.976575;-0.040645;,
  0.198913;-0.979115;-0.042048;,
  0.206443;0.541710;0.814820;,
  0.108120;-0.992262;-0.061045;,
  0.225559;-0.833955;-0.503630;,
  0.225232;-0.175026;-0.958455;,
  0.198767;-0.964475;-0.174010;,
  0.219927;0.487782;-0.844808;,
  0.206132;-0.978236;-0.023761;,
  0.192286;-0.978324;-0.076865;,
  0.107036;-0.493573;0.863092;,
  0.128295;0.513308;-0.848561;,
  0.211962;-0.481522;0.850417;,
  0.218860;-0.484311;0.847079;,
  0.215967;0.108391;-0.970366;,
  -0.000001;0.499979;-0.866037;,
  0.000000;0.499981;0.866036;,
  0.000000;0.499981;0.866037;,
  0.074036;-0.997232;-0.006780;,
  0.107005;0.497078;-0.861083;,
  0.074832;0.996917;0.023602;,
  0.146801;0.561440;0.814392;,
  0.156155;0.468319;0.869651;,
  0.217546;0.488024;-0.845285;,
  0.227055;0.486965;-0.843393;,
  0.194337;0.547190;0.814136;,
  0.110402;-0.501432;-0.858124;,
  0.108244;-0.503150;-0.857393;,
  0.184945;0.677037;0.712332;,
  0.211380;-0.976550;-0.040853;,
  0.237098;-0.841175;-0.486013;,
  0.217431;0.975685;-0.027635;,
  0.227064;-0.486928;0.843411;,
  0.227066;-0.487118;0.843301;,
  0.211310;-0.976577;-0.040566;,
  0.211349;-0.523511;-0.825389;,
  0.245781;0.465885;-0.850025;,
  0.226974;0.487357;-0.843188;,
  0.209607;-0.394569;0.894640;,
  0.217897;-0.440607;0.870854;,
  0.227062;-0.486739;0.843521;;
  86;
  4;0,0,0,5;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,6,46;,
  4;4,4,4,4;,
  4;47,47,48,48;,
  3;7,5,41;,
  3;41,5,8;,
  3;5,0,8;,
  3;9,24,1;,
  3;24,29,1;,
  3;29,34,1;,
  3;34,49,1;,
  3;49,1,1;,
  4;2,2,10,2;,
  3;50,46,42;,
  3;42,46,11;,
  3;46,6,11;,
  3;12,25,4;,
  3;25,51,4;,
  3;51,4,4;,
  4;48,48,52,53;,
  4;18,43,44,30;,
  4;19,37,40,31;,
  4;20,21,36,35;,
  3;54,38,55;,
  4;22,28,26,15;,
  3;16,23,13;,
  3;13,23,56;,
  3;23,33,56;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;17,17,17;,
  3;14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  3;14,14,14;,
  4;14,14,14,14;,
  4;7,41,43,18;,
  4;49,34,37,19;,
  4;9,10,21,20;,
  3;50,42,54;,
  3;54,42,38;,
  3;57,45,58;,
  4;51,25,28,22;,
  3;23,53,33;,
  3;59,33,52;,
  3;33,53,52;,
  4;60,39,35,61;,
  4;26,28,62,16;,
  3;14,14,14;,
  3;14,14,14;,
  4;14,14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  3;14,14,14;,
  4;27,24,9,20;,
  4;28,25,12,62;,
  4;30,44,63,64;,
  3;60,65,39;,
  3;65,31,39;,
  3;31,40,39;,
  3;56,33,59;,
  4;32,29,24,27;,
  3;40,37,32;,
  4;35,36,66,61;,
  3;58,45,36;,
  3;45,67,36;,
  3;67,68,36;,
  4;37,34,29,32;,
  4;35,39,27,20;,
  4;39,40,32,27;,
  4;44,43,69,70;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  3;14,14,14;,
  4;43,41,8,69;,
  4;45,42,11,22;,
  3;14,14,14;,
  3;14,14,14;,
  4;63,44,70,71;,
  4;67,45,22,15;;
 }
 MeshTextureCoords {
  86;
  0.375000;0.312500;,
  0.416670;0.312500;,
  0.416670;0.437810;,
  0.375000;0.437810;,
  0.458330;0.312500;,
  0.458330;0.437810;,
  0.500000;0.312500;,
  0.500000;0.437810;,
  0.541670;0.312500;,
  0.541670;0.437810;,
  0.583330;0.312500;,
  0.583330;0.437810;,
  0.625000;0.312500;,
  0.625000;0.437810;,
  0.375000;0.563130;,
  0.398250;0.563130;,
  0.416670;0.563130;,
  0.458330;0.563130;,
  0.437400;0.563130;,
  0.435590;0.563130;,
  0.421880;0.563130;,
  0.500000;0.563130;,
  0.518260;0.563130;,
  0.541670;0.563130;,
  0.583330;0.563130;,
  0.564240;0.563130;,
  0.625000;0.563130;,
  0.375000;0.626370;,
  0.397890;0.626370;,
  0.396380;0.674700;,
  0.375000;0.674450;,
  0.416670;0.626370;,
  0.425970;0.626370;,
  0.425750;0.646960;,
  0.416670;0.674940;,
  0.458330;0.626370;,
  0.500000;0.626370;,
  0.500000;0.674840;,
  0.458330;0.680840;,
  0.515780;0.626370;,
  0.541670;0.626370;,
  0.563820;0.626370;,
  0.555830;0.688440;,
  0.541670;0.688440;,
  0.583330;0.688440;,
  0.583330;0.626370;,
  0.625000;0.688440;,
  0.625000;0.674450;,
  0.609960;0.626370;,
  0.421880;0.020930;,
  0.578120;0.020930;,
  0.500000;0.150000;,
  0.343750;0.156250;,
  0.421880;0.291570;,
  0.578120;0.291570;,
  0.656250;0.156250;,
  0.578120;0.979070;,
  0.517890;0.979070;,
  0.517670;0.869510;,
  0.421880;0.979070;,
  0.367220;0.884400;,
  0.441470;0.839840;,
  0.500000;0.837500;,
  0.343750;0.843750;,
  0.421880;0.708430;,
  0.485950;0.814280;,
  0.517310;0.708430;,
  0.517510;0.797800;,
  0.578120;0.708430;,
  0.604670;0.754420;,
  0.527040;0.792820;,
  0.656250;0.843750;,
  0.517600;0.838200;,
  0.518620;0.626370;,
  0.625000;0.626370;,
  0.445820;0.688440;,
  0.443200;0.668160;,
  0.458330;0.688440;,
  0.517540;0.808530;,
  0.437820;0.626370;,
  0.391060;0.688440;,
  0.375000;0.688440;,
  0.416670;0.688440;,
  0.432430;0.626370;,
  0.500000;0.688440;,
  0.525450;0.688440;;
 }
}
