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
 125;
 0.54645;-0.09637;-0.08220;,
 0.58345;-0.04687;-0.10780;,
 0.47105;-0.05267;-0.15490;,
 0.46105;-0.11787;-0.10780;,
 0.33655;-0.05847;-0.17080;,
 0.33655;-0.12847;-0.12040;,
 0.48105;0.02553;-0.17080;,
 0.33655;0.02553;-0.18760;,
 0.60165;0.02553;-0.12040;,
 0.20205;-0.05267;-0.15490;,
 0.21205;-0.11787;-0.10780;,
 0.08965;-0.04687;-0.10780;,
 0.12665;-0.09637;-0.08220;,
 0.19205;0.02553;-0.17080;,
 0.07145;0.02553;-0.12040;,
 0.33655;0.10943;-0.17080;,
 0.20205;0.10363;-0.15490;,
 0.08965;0.09783;-0.10780;,
 0.21205;0.16883;-0.10780;,
 0.12665;0.14743;-0.08220;,
 0.33655;0.17943;-0.12040;,
 0.58345;0.09783;-0.10780;,
 0.47105;0.10363;-0.15490;,
 0.46105;0.16883;-0.10780;,
 0.54645;0.14743;-0.08220;,
 0.58345;0.16883;-0.02300;,
 0.47105;0.20833;-0.02990;,
 0.33655;0.22163;-0.03690;,
 0.48105;0.22163;0.06330;,
 0.33655;0.23573;0.06330;,
 0.60165;0.17943;0.06330;,
 0.20205;0.20833;-0.02990;,
 0.08965;0.16883;-0.02300;,
 0.19205;0.22163;0.06330;,
 0.07145;0.17943;0.06330;,
 0.33655;0.22163;0.16350;,
 0.20205;0.20833;0.15650;,
 0.08965;0.16883;0.14960;,
 0.21205;0.16883;0.23440;,
 0.12665;0.14743;0.20880;,
 0.33655;0.17943;0.24700;,
 0.58345;0.16883;0.14960;,
 0.47105;0.20833;0.15650;,
 0.46105;0.16883;0.23440;,
 0.54645;0.14743;0.20880;,
 0.58345;0.09783;0.23440;,
 0.47105;0.10363;0.28150;,
 0.33655;0.10943;0.29740;,
 0.48105;0.02553;0.29740;,
 0.33655;0.02553;0.31420;,
 0.60165;0.02553;0.24700;,
 0.20205;0.10363;0.28150;,
 0.08965;0.09783;0.23440;,
 0.19205;0.02553;0.29740;,
 0.07145;0.02553;0.24700;,
 0.33655;-0.05847;0.29740;,
 0.20205;-0.05267;0.28150;,
 0.08965;-0.04687;0.23440;,
 0.21205;-0.11787;0.23440;,
 0.12665;-0.09637;0.20880;,
 0.33655;-0.12847;0.24700;,
 0.58345;-0.04687;0.23440;,
 0.47105;-0.05267;0.28150;,
 0.46105;-0.11787;0.23440;,
 0.54645;-0.09637;0.20880;,
 0.58345;-0.11787;0.14960;,
 0.47105;-0.15737;0.15650;,
 0.33655;-0.17067;0.16350;,
 0.48105;-0.17067;0.06330;,
 0.33655;-0.18477;0.06330;,
 0.60165;-0.12847;0.06330;,
 0.20205;-0.15737;0.15650;,
 0.08965;-0.11787;0.14960;,
 0.19205;-0.17067;0.06330;,
 0.07145;-0.12847;0.06330;,
 0.33655;-0.17067;-0.03690;,
 0.20205;-0.15737;-0.02990;,
 0.08965;-0.11787;-0.02300;,
 0.21205;-0.11787;-0.10780;,
 0.12665;-0.09637;-0.08220;,
 0.33655;-0.12847;-0.12040;,
 0.58345;-0.11787;-0.02300;,
 0.47105;-0.15737;-0.02990;,
 0.46105;-0.11787;-0.10780;,
 0.54645;-0.09637;-0.08220;,
 0.02175;-0.05267;-0.02990;,
 0.08965;-0.11787;-0.02300;,
 -0.00115;-0.05847;0.06330;,
 0.07145;-0.12847;0.06330;,
 -0.00115;0.02553;-0.03690;,
 -0.02555;0.02553;0.06330;,
 0.02175;-0.05267;0.15650;,
 0.08965;-0.11787;0.14960;,
 0.08965;-0.04687;0.23440;,
 0.12665;-0.09637;0.20880;,
 -0.00115;0.02553;0.16350;,
 0.07145;0.02553;0.24700;,
 -0.00115;0.10943;0.06330;,
 0.02175;0.10363;0.15650;,
 0.08965;0.09783;0.23440;,
 0.08965;0.16883;0.14960;,
 0.12665;0.14743;0.20880;,
 0.07145;0.17943;0.06330;,
 0.02175;0.10363;-0.02990;,
 0.08965;0.16883;-0.02300;,
 0.54645;-0.09637;0.20880;,
 0.58345;-0.04687;0.23440;,
 0.65145;-0.05267;0.15650;,
 0.58345;-0.11787;0.14960;,
 0.67435;-0.05847;0.06330;,
 0.60165;-0.12847;0.06330;,
 0.67435;0.02553;0.16350;,
 0.69865;0.02553;0.06330;,
 0.60165;0.02553;0.24700;,
 0.65145;-0.05267;-0.02990;,
 0.58345;-0.11787;-0.02300;,
 0.67435;0.02553;-0.03690;,
 0.67435;0.10943;0.06330;,
 0.65145;0.10363;-0.02990;,
 0.58345;0.16883;-0.02300;,
 0.60165;0.17943;0.06330;,
 0.58345;0.09783;0.23440;,
 0.65145;0.10363;0.15650;,
 0.58345;0.16883;0.14960;,
 0.54645;0.14743;0.20880;;
 
 192;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;2,6,7,4;,
 4;1,8,6,2;,
 4;5,4,9,10;,
 4;10,9,11,12;,
 4;9,13,14,11;,
 4;4,7,13,9;,
 4;7,15,16,13;,
 4;13,16,17,14;,
 4;16,18,19,17;,
 4;15,20,18,16;,
 4;8,21,22,6;,
 4;6,22,15,7;,
 4;22,23,20,15;,
 4;21,24,23,22;,
 4;24,25,26,23;,
 4;23,26,27,20;,
 4;26,28,29,27;,
 4;25,30,28,26;,
 4;20,27,31,18;,
 4;18,31,32,19;,
 4;31,33,34,32;,
 4;27,29,33,31;,
 4;29,35,36,33;,
 4;33,36,37,34;,
 4;36,38,39,37;,
 4;35,40,38,36;,
 4;30,41,42,28;,
 4;28,42,35,29;,
 4;42,43,40,35;,
 4;41,44,43,42;,
 4;44,45,46,43;,
 4;43,46,47,40;,
 4;46,48,49,47;,
 4;45,50,48,46;,
 4;40,47,51,38;,
 4;38,51,52,39;,
 4;51,53,54,52;,
 4;47,49,53,51;,
 4;49,55,56,53;,
 4;53,56,57,54;,
 4;56,58,59,57;,
 4;55,60,58,56;,
 4;50,61,62,48;,
 4;48,62,55,49;,
 4;62,63,60,55;,
 4;61,64,63,62;,
 4;64,65,66,63;,
 4;63,66,67,60;,
 4;66,68,69,67;,
 4;65,70,68,66;,
 4;60,67,71,58;,
 4;58,71,72,59;,
 4;71,73,74,72;,
 4;67,69,73,71;,
 4;69,75,76,73;,
 4;73,76,77,74;,
 4;76,78,79,77;,
 4;75,80,78,76;,
 4;70,81,82,68;,
 4;68,82,75,69;,
 4;82,83,80,75;,
 4;81,84,83,82;,
 4;12,11,85,86;,
 4;86,85,87,88;,
 4;85,89,90,87;,
 4;11,14,89,85;,
 4;88,87,91,92;,
 4;92,91,93,94;,
 4;91,95,96,93;,
 4;87,90,95,91;,
 4;90,97,98,95;,
 4;95,98,99,96;,
 4;98,100,101,99;,
 4;97,102,100,98;,
 4;14,17,103,89;,
 4;89,103,97,90;,
 4;103,104,102,97;,
 4;17,19,104,103;,
 4;105,106,107,108;,
 4;108,107,109,110;,
 4;107,111,112,109;,
 4;106,113,111,107;,
 4;110,109,114,115;,
 4;115,114,1,0;,
 4;114,116,8,1;,
 4;109,112,116,114;,
 4;112,117,118,116;,
 4;116,118,21,8;,
 4;118,119,24,21;,
 4;117,120,119,118;,
 4;113,121,122,111;,
 4;111,122,117,112;,
 4;122,123,120,117;,
 4;121,124,123,122;,
 4;3,2,1,0;,
 4;5,4,2,3;,
 4;4,7,6,2;,
 4;2,6,8,1;,
 4;10,9,4,5;,
 4;12,11,9,10;,
 4;11,14,13,9;,
 4;9,13,7,4;,
 4;13,16,15,7;,
 4;14,17,16,13;,
 4;17,19,18,16;,
 4;16,18,20,15;,
 4;6,22,21,8;,
 4;7,15,22,6;,
 4;15,20,23,22;,
 4;22,23,24,21;,
 4;23,26,25,24;,
 4;20,27,26,23;,
 4;27,29,28,26;,
 4;26,28,30,25;,
 4;18,31,27,20;,
 4;19,32,31,18;,
 4;32,34,33,31;,
 4;31,33,29,27;,
 4;33,36,35,29;,
 4;34,37,36,33;,
 4;37,39,38,36;,
 4;36,38,40,35;,
 4;28,42,41,30;,
 4;29,35,42,28;,
 4;35,40,43,42;,
 4;42,43,44,41;,
 4;43,46,45,44;,
 4;40,47,46,43;,
 4;47,49,48,46;,
 4;46,48,50,45;,
 4;38,51,47,40;,
 4;39,52,51,38;,
 4;52,54,53,51;,
 4;51,53,49,47;,
 4;53,56,55,49;,
 4;54,57,56,53;,
 4;57,59,58,56;,
 4;56,58,60,55;,
 4;48,62,61,50;,
 4;49,55,62,48;,
 4;55,60,63,62;,
 4;62,63,64,61;,
 4;63,66,65,64;,
 4;60,67,66,63;,
 4;67,69,68,66;,
 4;66,68,70,65;,
 4;58,71,67,60;,
 4;59,72,71,58;,
 4;72,74,73,71;,
 4;71,73,69,67;,
 4;73,76,75,69;,
 4;74,77,76,73;,
 4;77,79,78,76;,
 4;76,78,80,75;,
 4;68,82,81,70;,
 4;69,75,82,68;,
 4;75,80,83,82;,
 4;82,83,84,81;,
 4;86,85,11,12;,
 4;88,87,85,86;,
 4;87,90,89,85;,
 4;85,89,14,11;,
 4;92,91,87,88;,
 4;94,93,91,92;,
 4;93,96,95,91;,
 4;91,95,90,87;,
 4;95,98,97,90;,
 4;96,99,98,95;,
 4;99,101,100,98;,
 4;98,100,102,97;,
 4;89,103,17,14;,
 4;90,97,103,89;,
 4;97,102,104,103;,
 4;103,104,19,17;,
 4;108,107,106,105;,
 4;110,109,107,108;,
 4;109,112,111,107;,
 4;107,111,113,106;,
 4;115,114,109,110;,
 4;0,1,114,115;,
 4;1,8,116,114;,
 4;114,116,112,109;,
 4;116,118,117,112;,
 4;8,21,118,116;,
 4;21,24,119,118;,
 4;118,119,120,117;,
 4;111,122,121,113;,
 4;112,117,122,111;,
 4;117,120,123,122;,
 4;122,123,124,121;;
 
 MeshMaterialList {
  13;
  192;
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11;;
  Material {
   0.736000;0.544000;0.432000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.120000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.400000;0.400000;0.400000;1.000000;;
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
  Material {
   0.344000;0.344000;0.392000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.120000;0.112000;0.152000;1.000000;;
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
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.344000;0.344000;0.392000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.048000;0.048000;0.048000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.760000;0.600000;0.432000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.310588;0.310588;0.310588;1.000000;;
   5.000000;
   1.000000;1.000000;1.000000;;
   0.194118;0.194118;0.194118;;
  }
 }
 MeshNormals {
  196;
  -0.408137;0.697927;0.588491;,
  0.408241;0.697892;0.588461;,
  -0.408215;-0.697932;0.588431;,
  0.408319;-0.697897;0.588401;,
  -0.408215;-0.697932;-0.588431;,
  0.408319;-0.697897;-0.588401;,
  -0.408137;0.697927;-0.588491;,
  0.408241;0.697892;-0.588461;,
  -0.521510;-0.853245;0.000000;,
  0.583273;-0.000172;-0.812276;,
  -0.000000;0.760563;-0.649264;,
  -0.582993;-0.000172;-0.812477;,
  0.521808;0.853063;0.000000;,
  -0.521512;0.853244;0.000000;,
  -0.000000;0.760563;0.649264;,
  0.583273;-0.000172;0.812276;,
  -0.000000;-0.760565;0.649262;,
  -0.582993;-0.000172;0.812477;,
  0.521807;-0.853064;-0.000000;,
  -0.000000;-0.760565;-0.649262;,
  -0.000000;-0.000125;1.000000;,
  -0.000000;-1.000000;0.000000;,
  -0.000000;-0.000125;-1.000000;,
  -0.000000;1.000000;0.000000;,
  1.000000;-0.000173;-0.000000;,
  -1.000000;-0.000173;0.000000;,
  -0.250171;0.419694;0.872509;,
  0.250170;0.419694;0.872509;,
  0.250096;-0.419712;0.872522;,
  -0.250096;-0.419712;0.872521;,
  -0.223443;-0.921128;0.318743;,
  0.223443;-0.921128;0.318743;,
  0.223443;-0.921128;-0.318743;,
  -0.223443;-0.921128;-0.318743;,
  -0.250096;-0.419712;-0.872521;,
  0.250096;-0.419712;-0.872522;,
  0.250170;0.419694;-0.872509;,
  -0.250171;0.419694;-0.872509;,
  -0.223548;0.921051;-0.318890;,
  0.223547;0.921051;-0.318890;,
  0.223547;0.921051;0.318890;,
  -0.223548;0.921051;0.318890;,
  0.748795;0.504554;0.429804;,
  0.748795;0.504554;-0.429804;,
  0.748843;-0.504595;-0.429672;,
  0.748843;-0.504595;0.429672;,
  -0.748669;0.504651;-0.429909;,
  -0.748669;0.504651;0.429909;,
  -0.748718;-0.504692;0.429776;,
  -0.748718;-0.504692;-0.429776;,
  -0.000000;0.406956;0.913448;,
  0.257923;-0.000141;0.966166;,
  -0.000000;-0.407068;0.913398;,
  -0.257923;-0.000141;0.966165;,
  -0.000000;-0.952238;0.305356;,
  0.219767;-0.975552;-0.000000;,
  -0.000000;-0.952238;-0.305356;,
  -0.219767;-0.975552;0.000000;,
  -0.000000;-0.407068;-0.913398;,
  0.257923;-0.000141;-0.966166;,
  -0.000000;0.406956;-0.913448;,
  -0.257923;-0.000141;-0.966165;,
  -0.000000;0.952237;-0.305360;,
  0.219770;0.975552;0.000000;,
  -0.000000;0.952237;0.305360;,
  -0.219770;0.975552;0.000000;,
  0.850410;0.526121;0.000000;,
  0.883897;-0.000178;-0.467681;,
  0.850320;-0.526266;0.000000;,
  0.883897;-0.000178;0.467681;,
  -0.850385;0.526160;0.000000;,
  -0.883860;-0.000178;0.467751;,
  -0.850296;-0.526305;0.000000;,
  -0.883860;-0.000178;-0.467751;,
  -0.235856;0.740492;0.629320;,
  0.235855;0.740492;0.629320;,
  0.512933;0.459135;0.725324;,
  0.513000;-0.459108;0.725293;,
  0.235719;-0.740543;0.629312;,
  -0.235720;-0.740542;0.629312;,
  -0.512797;-0.459117;0.725432;,
  -0.512729;0.459144;0.725463;,
  0.479203;-0.798679;0.363971;,
  0.479203;-0.798679;-0.363971;,
  0.235719;-0.740543;-0.629312;,
  -0.235720;-0.740543;-0.629312;,
  -0.478986;-0.798810;-0.363971;,
  -0.478986;-0.798810;0.363971;,
  0.513000;-0.459108;-0.725293;,
  0.512933;0.459135;-0.725324;,
  0.235855;0.740492;-0.629320;,
  -0.235856;0.740492;-0.629320;,
  -0.512729;0.459144;-0.725463;,
  -0.512797;-0.459117;-0.725432;,
  0.479126;0.798636;-0.364168;,
  0.479126;0.798636;0.364168;,
  -0.478909;0.798766;0.364168;,
  -0.478909;0.798766;-0.364168;,
  0.235856;-0.740492;-0.629320;,
  0.250171;-0.419694;-0.872509;,
  0.512729;-0.459144;-0.725463;,
  0.408137;-0.697927;-0.588491;,
  0.000000;-0.760563;-0.649264;,
  0.000000;-0.406956;-0.913448;,
  0.000000;0.000125;-1.000000;,
  0.257923;0.000141;-0.966165;,
  0.582993;0.000172;-0.812477;,
  -0.235855;-0.740492;-0.629320;,
  -0.250170;-0.419694;-0.872509;,
  -0.408241;-0.697892;-0.588461;,
  -0.512933;-0.459135;-0.725324;,
  -0.583273;0.000172;-0.812276;,
  -0.257923;0.000141;-0.966166;,
  -0.250096;0.419712;-0.872522;,
  0.000000;0.407068;-0.913398;,
  -0.513000;0.459108;-0.725293;,
  -0.408319;0.697897;-0.588401;,
  -0.235719;0.740543;-0.629312;,
  0.000000;0.760565;-0.649262;,
  0.250096;0.419712;-0.872521;,
  0.512797;0.459117;-0.725432;,
  0.235720;0.740542;-0.629312;,
  0.408215;0.697932;-0.588431;,
  0.223443;0.921128;-0.318743;,
  0.478986;0.798810;-0.363971;,
  0.000000;0.952238;-0.305356;,
  0.000000;1.000000;0.000000;,
  0.219767;0.975552;0.000000;,
  0.521510;0.853245;-0.000000;,
  -0.223443;0.921128;-0.318743;,
  -0.479203;0.798679;-0.363971;,
  -0.521807;0.853064;0.000000;,
  -0.219767;0.975552;0.000000;,
  -0.223443;0.921128;0.318743;,
  0.000000;0.952238;0.305356;,
  -0.479203;0.798679;0.363971;,
  -0.408319;0.697897;0.588401;,
  -0.235719;0.740543;0.629312;,
  0.000000;0.760565;0.649262;,
  0.223443;0.921128;0.318743;,
  0.478986;0.798810;0.363971;,
  0.235720;0.740543;0.629312;,
  0.408215;0.697932;0.588431;,
  0.250096;0.419712;0.872521;,
  0.512797;0.459117;0.725432;,
  0.000000;0.407068;0.913398;,
  0.000000;0.000125;1.000000;,
  0.257923;0.000141;0.966165;,
  0.582993;0.000172;0.812477;,
  -0.250096;0.419712;0.872522;,
  -0.513000;0.459108;0.725293;,
  -0.583273;0.000172;0.812276;,
  -0.257923;0.000141;0.966166;,
  -0.250170;-0.419694;0.872509;,
  0.000000;-0.406956;0.913448;,
  -0.512933;-0.459135;0.725324;,
  -0.408241;-0.697892;0.588461;,
  -0.235855;-0.740492;0.629320;,
  0.000000;-0.760563;0.649264;,
  0.250171;-0.419694;0.872509;,
  0.512729;-0.459144;0.725463;,
  0.235856;-0.740492;0.629320;,
  0.408137;-0.697927;0.588491;,
  0.223548;-0.921051;0.318890;,
  0.478909;-0.798766;0.364168;,
  0.000000;-0.952237;0.305360;,
  0.000000;-1.000000;-0.000000;,
  0.219770;-0.975552;-0.000000;,
  0.521512;-0.853244;-0.000000;,
  -0.223547;-0.921051;0.318890;,
  -0.479126;-0.798636;0.364168;,
  -0.521808;-0.853063;0.000000;,
  -0.219770;-0.975552;0.000000;,
  -0.223547;-0.921051;-0.318890;,
  0.000000;-0.952237;-0.305360;,
  -0.479126;-0.798636;-0.364168;,
  0.223548;-0.921051;-0.318890;,
  0.478909;-0.798766;-0.364168;,
  -0.748795;-0.504554;-0.429804;,
  -0.850410;-0.526121;0.000000;,
  -1.000000;0.000173;0.000000;,
  -0.883897;0.000178;-0.467681;,
  -0.748795;-0.504554;0.429804;,
  -0.883897;0.000178;0.467681;,
  -0.748843;0.504595;0.429672;,
  -0.850320;0.526266;-0.000000;,
  -0.748843;0.504595;-0.429672;,
  0.748669;-0.504651;0.429909;,
  0.850385;-0.526160;-0.000000;,
  1.000000;0.000173;0.000000;,
  0.883860;0.000178;0.467751;,
  0.748669;-0.504651;-0.429909;,
  0.883860;0.000178;-0.467751;,
  0.748718;0.504692;-0.429776;,
  0.850296;0.526305;-0.000000;,
  0.748718;0.504692;0.429776;;
  192;
  4;0,81,26,74;,
  4;74,26,50,14;,
  4;26,53,20,50;,
  4;81,17,53,26;,
  4;14,50,27,75;,
  4;75,27,76,1;,
  4;27,51,15,76;,
  4;50,20,51,27;,
  4;20,52,28,51;,
  4;51,28,77,15;,
  4;28,78,3,77;,
  4;52,16,78,28;,
  4;17,80,29,53;,
  4;53,29,52,20;,
  4;29,79,16,52;,
  4;80,2,79,29;,
  4;2,87,30,79;,
  4;79,30,54,16;,
  4;30,57,21,54;,
  4;87,8,57,30;,
  4;16,54,31,78;,
  4;78,31,82,3;,
  4;31,55,18,82;,
  4;54,21,55,31;,
  4;21,56,32,55;,
  4;55,32,83,18;,
  4;32,84,5,83;,
  4;56,19,84,32;,
  4;8,86,33,57;,
  4;57,33,56,21;,
  4;33,85,19,56;,
  4;86,4,85,33;,
  4;4,93,34,85;,
  4;85,34,58,19;,
  4;34,61,22,58;,
  4;93,11,61,34;,
  4;19,58,35,84;,
  4;84,35,88,5;,
  4;35,59,9,88;,
  4;58,22,59,35;,
  4;22,60,36,59;,
  4;59,36,89,9;,
  4;36,90,7,89;,
  4;60,10,90,36;,
  4;11,92,37,61;,
  4;61,37,60,22;,
  4;37,91,10,60;,
  4;92,6,91,37;,
  4;6,97,38,91;,
  4;91,38,62,10;,
  4;38,65,23,62;,
  4;97,13,65,38;,
  4;10,62,39,90;,
  4;90,39,94,7;,
  4;39,63,12,94;,
  4;62,23,63,39;,
  4;23,64,40,63;,
  4;63,40,95,12;,
  4;40,75,1,95;,
  4;64,14,75,40;,
  4;13,96,41,65;,
  4;65,41,64,23;,
  4;41,74,14,64;,
  4;96,0,74,41;,
  4;1,76,42,95;,
  4;95,42,66,12;,
  4;42,69,24,66;,
  4;76,15,69,42;,
  4;12,66,43,94;,
  4;94,43,89,7;,
  4;43,67,9,89;,
  4;66,24,67,43;,
  4;24,68,44,67;,
  4;67,44,88,9;,
  4;44,83,5,88;,
  4;68,18,83,44;,
  4;15,77,45,69;,
  4;69,45,68,24;,
  4;45,82,18,68;,
  4;77,3,82,45;,
  4;6,92,46,97;,
  4;97,46,70,13;,
  4;46,73,25,70;,
  4;92,11,73,46;,
  4;13,70,47,96;,
  4;96,47,81,0;,
  4;47,71,17,81;,
  4;70,25,71,47;,
  4;25,72,48,71;,
  4;71,48,80,17;,
  4;48,87,2,80;,
  4;72,8,87,48;,
  4;11,93,49,73;,
  4;73,49,72,25;,
  4;49,86,8,72;,
  4;93,4,86,49;,
  4;98,99,100,101;,
  4;102,103,99,98;,
  4;103,104,105,99;,
  4;99,105,106,100;,
  4;107,108,103,102;,
  4;109,110,108,107;,
  4;110,111,112,108;,
  4;108,112,104,103;,
  4;112,113,114,104;,
  4;111,115,113,112;,
  4;115,116,117,113;,
  4;113,117,118,114;,
  4;105,119,120,106;,
  4;104,114,119,105;,
  4;114,118,121,119;,
  4;119,121,122,120;,
  4;121,123,124,122;,
  4;118,125,123,121;,
  4;125,126,127,123;,
  4;123,127,128,124;,
  4;117,129,125,118;,
  4;116,130,129,117;,
  4;130,131,132,129;,
  4;129,132,126,125;,
  4;132,133,134,126;,
  4;131,135,133,132;,
  4;135,136,137,133;,
  4;133,137,138,134;,
  4;127,139,140,128;,
  4;126,134,139,127;,
  4;134,138,141,139;,
  4;139,141,142,140;,
  4;141,143,144,142;,
  4;138,145,143,141;,
  4;145,146,147,143;,
  4;143,147,148,144;,
  4;137,149,145,138;,
  4;136,150,149,137;,
  4;150,151,152,149;,
  4;149,152,146,145;,
  4;152,153,154,146;,
  4;151,155,153,152;,
  4;155,156,157,153;,
  4;153,157,158,154;,
  4;147,159,160,148;,
  4;146,154,159,147;,
  4;154,158,161,159;,
  4;159,161,162,160;,
  4;161,163,164,162;,
  4;158,165,163,161;,
  4;165,166,167,163;,
  4;163,167,168,164;,
  4;157,169,165,158;,
  4;156,170,169,157;,
  4;170,171,172,169;,
  4;169,172,166,165;,
  4;172,173,174,166;,
  4;171,175,173,172;,
  4;175,109,107,173;,
  4;173,107,102,174;,
  4;167,176,177,168;,
  4;166,174,176,167;,
  4;174,102,98,176;,
  4;176,98,101,177;,
  4;175,178,110,109;,
  4;171,179,178,175;,
  4;179,180,181,178;,
  4;178,181,111,110;,
  4;170,182,179,171;,
  4;156,155,182,170;,
  4;155,151,183,182;,
  4;182,183,180,179;,
  4;183,184,185,180;,
  4;151,150,184,183;,
  4;150,136,135,184;,
  4;184,135,131,185;,
  4;181,186,115,111;,
  4;180,185,186,181;,
  4;185,131,130,186;,
  4;186,130,116,115;,
  4;164,187,160,162;,
  4;168,188,187,164;,
  4;188,189,190,187;,
  4;187,190,148,160;,
  4;177,191,188,168;,
  4;101,100,191,177;,
  4;100,106,192,191;,
  4;191,192,189,188;,
  4;192,193,194,189;,
  4;106,120,193,192;,
  4;120,122,124,193;,
  4;193,124,128,194;,
  4;190,195,144,148;,
  4;189,194,195,190;,
  4;194,128,140,195;,
  4;195,140,142,144;;
 }
 MeshTextureCoords {
  125;
  0.375000;0.000000;,
  0.375000;0.062500;,
  0.437500;0.062500;,
  0.437500;0.000000;,
  0.500000;0.062500;,
  0.500000;0.000000;,
  0.437500;0.125000;,
  0.500000;0.125000;,
  0.375000;0.125000;,
  0.562500;0.062500;,
  0.562500;0.000000;,
  0.625000;0.062500;,
  0.625000;0.000000;,
  0.562500;0.125000;,
  0.625000;0.125000;,
  0.500000;0.187500;,
  0.562500;0.187500;,
  0.625000;0.187500;,
  0.562500;0.250000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.187500;,
  0.437500;0.187500;,
  0.437500;0.250000;,
  0.375000;0.250000;,
  0.375000;0.312500;,
  0.437500;0.312500;,
  0.500000;0.312500;,
  0.437500;0.375000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.562500;0.312500;,
  0.625000;0.312500;,
  0.562500;0.375000;,
  0.625000;0.375000;,
  0.500000;0.437500;,
  0.562500;0.437500;,
  0.625000;0.437500;,
  0.562500;0.500000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.375000;0.437500;,
  0.437500;0.437500;,
  0.437500;0.500000;,
  0.375000;0.500000;,
  0.375000;0.562500;,
  0.437500;0.562500;,
  0.500000;0.562500;,
  0.437500;0.625000;,
  0.500000;0.625000;,
  0.375000;0.625000;,
  0.562500;0.562500;,
  0.625000;0.562500;,
  0.562500;0.625000;,
  0.625000;0.625000;,
  0.500000;0.687500;,
  0.562500;0.687500;,
  0.625000;0.687500;,
  0.562500;0.750000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.687500;,
  0.437500;0.687500;,
  0.437500;0.750000;,
  0.375000;0.750000;,
  0.375000;0.812500;,
  0.437500;0.812500;,
  0.500000;0.812500;,
  0.437500;0.875000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.562500;0.812500;,
  0.625000;0.812500;,
  0.562500;0.875000;,
  0.625000;0.875000;,
  0.500000;0.937500;,
  0.562500;0.937500;,
  0.625000;0.937500;,
  0.562500;1.000000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.375000;0.937500;,
  0.437500;0.937500;,
  0.437500;1.000000;,
  0.375000;1.000000;,
  0.687500;0.062500;,
  0.687500;0.000000;,
  0.750000;0.062500;,
  0.750000;0.000000;,
  0.687500;0.125000;,
  0.750000;0.125000;,
  0.812500;0.062500;,
  0.812500;0.000000;,
  0.875000;0.062500;,
  0.875000;0.000000;,
  0.812500;0.125000;,
  0.875000;0.125000;,
  0.750000;0.187500;,
  0.812500;0.187500;,
  0.875000;0.187500;,
  0.812500;0.250000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.687500;0.187500;,
  0.687500;0.250000;,
  0.125000;0.000000;,
  0.125000;0.062500;,
  0.187500;0.062500;,
  0.187500;0.000000;,
  0.250000;0.062500;,
  0.250000;0.000000;,
  0.187500;0.125000;,
  0.250000;0.125000;,
  0.125000;0.125000;,
  0.312500;0.062500;,
  0.312500;0.000000;,
  0.312500;0.125000;,
  0.250000;0.187500;,
  0.312500;0.187500;,
  0.312500;0.250000;,
  0.250000;0.250000;,
  0.125000;0.187500;,
  0.187500;0.187500;,
  0.187500;0.250000;,
  0.125000;0.250000;;
 }
}
