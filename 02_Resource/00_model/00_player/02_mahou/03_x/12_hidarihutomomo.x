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
 78;
 -0.38462;-3.10496;-0.32710;,
 -0.51722;-2.96916;-0.43620;,
 -0.00572;-2.96916;-0.57650;,
 -0.00572;-3.15246;-0.43620;,
 0.50588;-2.96916;-0.43620;,
 0.37318;-3.10496;-0.32710;,
 -0.00572;-2.78576;-0.43620;,
 0.37318;-2.83336;-0.32710;,
 -0.38462;-2.83336;-0.32710;,
 -0.51722;-2.78576;-0.01550;,
 -0.00572;-2.72466;-0.01550;,
 0.50588;-2.78576;-0.01550;,
 -0.00572;-2.78576;0.40530;,
 0.37318;-2.83336;0.29620;,
 -0.38462;-2.83336;0.29620;,
 -0.51722;-2.96916;0.40530;,
 -0.00572;-2.96916;0.54560;,
 0.50588;-2.96916;0.40530;,
 -0.00572;-3.15246;0.40530;,
 0.37318;-3.10496;0.29620;,
 -0.38462;-3.10496;0.29620;,
 -0.51722;-3.15246;-0.01550;,
 -0.00572;-3.21356;-0.01550;,
 0.50588;-3.15246;-0.01550;,
 -0.00572;-3.15246;-0.43620;,
 0.37318;-3.10496;-0.32710;,
 -0.38462;-3.10496;-0.32710;,
 0.67638;-2.96916;-0.01550;,
 0.50588;-3.15246;-0.01550;,
 0.50588;-2.96916;0.40530;,
 0.37318;-3.10496;0.29620;,
 0.50588;-2.78576;-0.01550;,
 0.37318;-2.83336;0.29620;,
 -0.38462;-3.10496;0.29620;,
 -0.51722;-2.96916;0.40530;,
 -0.68772;-2.96916;-0.01550;,
 -0.51722;-3.15246;-0.01550;,
 -0.51722;-2.78576;-0.01550;,
 -0.38462;-2.83336;0.29620;,
 -0.47638;-2.71216;-0.45100;,
 -0.64118;-1.44616;-0.60890;,
 -0.00518;-1.44616;-0.81180;,
 -0.00518;-2.77486;-0.60890;,
 0.63082;-1.44616;-0.60890;,
 0.46592;-2.71216;-0.45100;,
 -0.00518;-0.11756;-0.60890;,
 0.46592;-0.46196;-0.45100;,
 -0.47638;-0.46196;-0.45100;,
 -0.64118;-0.11756;0.00000;,
 -0.00518;0.32534;0.00000;,
 0.63082;-0.11756;-0.00000;,
 -0.00518;-0.11756;0.60890;,
 0.46592;-0.46196;0.45100;,
 -0.47638;-0.46196;0.45100;,
 -0.64118;-1.44616;0.60890;,
 -0.00518;-1.44616;0.81180;,
 0.63082;-1.44616;0.60890;,
 -0.00518;-2.77486;0.60890;,
 0.46592;-2.73786;0.45100;,
 -0.47638;-2.73786;0.45100;,
 -0.64118;-2.77486;0.00000;,
 -0.00518;-2.91846;0.00000;,
 0.63082;-2.77486;-0.00000;,
 -0.00518;-2.77486;-0.60890;,
 0.46592;-2.71216;-0.45100;,
 -0.47638;-2.71216;-0.45100;,
 0.84282;-1.44616;-0.00000;,
 0.63082;-2.77486;-0.00000;,
 0.63082;-1.44616;0.60890;,
 0.46592;-2.73786;0.45100;,
 0.63082;-0.11756;-0.00000;,
 0.46592;-0.46196;0.45100;,
 -0.47638;-2.73786;0.45100;,
 -0.64118;-1.44616;0.60890;,
 -0.85318;-1.44616;0.00000;,
 -0.64118;-2.77486;0.00000;,
 -0.64118;-0.11756;0.00000;,
 -0.47638;-0.46196;0.45100;;
 
 48;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;2,6,7,4;,
 4;1,8,6,2;,
 4;8,9,10,6;,
 4;6,10,11,7;,
 4;10,12,13,11;,
 4;9,14,12,10;,
 4;14,15,16,12;,
 4;12,16,17,13;,
 4;16,18,19,17;,
 4;15,20,18,16;,
 4;20,21,22,18;,
 4;18,22,23,19;,
 4;22,24,25,23;,
 4;21,26,24,22;,
 4;5,4,27,28;,
 4;28,27,29,30;,
 4;27,31,32,29;,
 4;4,7,31,27;,
 4;33,34,35,36;,
 4;36,35,1,0;,
 4;35,37,8,1;,
 4;34,38,37,35;,
 4;39,40,41,42;,
 4;42,41,43,44;,
 4;41,45,46,43;,
 4;40,47,45,41;,
 4;47,48,49,45;,
 4;45,49,50,46;,
 4;49,51,52,50;,
 4;48,53,51,49;,
 4;53,54,55,51;,
 4;51,55,56,52;,
 4;55,57,58,56;,
 4;54,59,57,55;,
 4;59,60,61,57;,
 4;57,61,62,58;,
 4;61,63,64,62;,
 4;60,65,63,61;,
 4;44,43,66,67;,
 4;67,66,68,69;,
 4;66,70,71,68;,
 4;43,46,70,66;,
 4;72,73,74,75;,
 4;75,74,40,39;,
 4;74,76,47,40;,
 4;73,77,76,74;;
 
 MeshMaterialList {
  13;
  48;
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
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.024000;0.024000;0.024000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.248000;0.600000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.024000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.080000;0.016000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.080000;0.016000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.080000;0.016000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  73;
  -0.361211;-0.828867;-0.427207;,
  0.361151;-0.828888;-0.427218;,
  -0.361303;0.828769;-0.427319;,
  0.361243;0.828790;-0.427330;,
  -0.361316;0.828784;0.427280;,
  0.361255;0.828805;0.427290;,
  -0.361223;-0.828882;0.427168;,
  0.361163;-0.828903;0.427178;,
  -0.420260;0.907404;-0.000033;,
  0.457283;0.707742;0.538511;,
  -0.000009;-0.877856;0.478924;,
  -0.457363;0.707699;0.538500;,
  0.420074;-0.907490;-0.000033;,
  -0.420146;-0.907457;-0.000033;,
  -0.000009;-0.877845;-0.478945;,
  0.457189;-0.707844;-0.538456;,
  -0.000009;0.877778;-0.479068;,
  -0.457269;-0.707801;-0.538445;,
  0.420188;0.907437;-0.000033;,
  -0.000009;0.877790;0.479047;,
  -0.000012;-0.672575;-0.740029;,
  -0.000006;1.000000;-0.000024;,
  -0.000012;0.672482;0.740113;,
  -0.000006;-1.000000;-0.000024;,
  0.671349;-0.741141;-0.000040;,
  -0.671456;-0.741044;-0.000040;,
  -0.687356;-0.168056;-0.706611;,
  0.687331;-0.168074;-0.706631;,
  -0.651594;0.347496;-0.674294;,
  0.651584;0.347485;-0.674309;,
  -0.651594;0.347496;0.674294;,
  0.651584;0.347485;0.674309;,
  -0.687589;-0.166867;0.706666;,
  0.687563;-0.166884;0.706687;,
  -0.903274;0.370062;-0.217140;,
  0.696783;0.011847;0.717184;,
  0.000016;-0.155918;0.987770;,
  -0.696804;0.011844;0.717164;,
  0.201052;-0.979496;-0.012833;,
  -0.201034;-0.979500;-0.012834;,
  0.000016;-0.157524;-0.987515;,
  0.696743;0.011084;-0.717235;,
  0.000020;0.467677;-0.883900;,
  -0.696764;0.011081;-0.717215;,
  0.761948;0.415941;-0.496416;,
  0.469386;0.412944;0.780483;,
  0.000018;0.010633;-0.999943;,
  -0.543491;0.618351;-0.567680;,
  0.000018;0.011350;0.999936;,
  0.000009;-0.999914;-0.013101;,
  0.999936;0.011297;-0.000984;,
  -0.999936;0.011291;-0.000984;,
  -0.000012;0.672482;-0.740113;,
  0.457262;0.707729;-0.538545;,
  -0.457343;0.707686;-0.538534;,
  -0.000012;-0.672575;0.740029;,
  0.457209;-0.707857;0.538422;,
  -0.457290;-0.707814;0.538411;,
  0.671443;0.741057;-0.000040;,
  -0.671549;0.740960;-0.000040;,
  0.543522;0.618293;-0.567712;,
  0.543522;0.618293;0.567712;,
  0.761948;0.415941;0.496416;,
  -0.543491;0.618351;0.567680;,
  -0.469357;0.412973;0.780485;,
  -0.184725;-0.963674;0.192899;,
  0.000007;-0.980546;0.196288;,
  0.184739;-0.963666;0.192922;,
  0.000010;-0.974832;-0.222939;,
  0.208750;-0.953353;-0.218039;,
  -0.208731;-0.953363;-0.218017;,
  0.986534;-0.163548;-0.001921;,
  -0.986540;-0.163510;-0.001921;;
  48;
  4;0,17,20,14;,
  4;14,20,15,1;,
  4;52,16,3,53;,
  4;54,2,16,52;,
  4;2,8,21,16;,
  4;16,21,18,3;,
  4;21,19,5,18;,
  4;8,4,19,21;,
  4;4,11,22,19;,
  4;19,22,9,5;,
  4;55,10,7,56;,
  4;57,6,10,55;,
  4;6,13,23,10;,
  4;10,23,12,7;,
  4;23,14,1,12;,
  4;13,0,14,23;,
  4;1,15,24,12;,
  4;12,24,56,7;,
  4;58,18,5,9;,
  4;53,3,18,58;,
  4;6,57,25,13;,
  4;13,25,17,0;,
  4;59,8,2,54;,
  4;11,4,8,59;,
  4;26,43,46,40;,
  4;40,46,41,27;,
  4;46,42,29,41;,
  4;43,28,42,46;,
  4;28,34,47,42;,
  4;42,60,44,29;,
  4;61,45,31,62;,
  4;63,30,64,63;,
  4;30,37,48,64;,
  4;45,48,35,31;,
  4;48,36,33,35;,
  4;37,32,36,48;,
  4;65,39,49,66;,
  4;66,49,38,67;,
  4;49,68,69,38;,
  4;39,70,68,49;,
  4;27,41,50,71;,
  4;71,50,35,33;,
  4;50,62,31,35;,
  4;41,29,44,50;,
  4;32,37,51,72;,
  4;72,51,43,26;,
  4;51,34,28,43;,
  4;37,30,34,51;;
 }
 MeshTextureCoords {
  78;
  0.375000;0.000000;,
  0.375000;0.125000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.125000;,
  0.250000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.125000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.125000;,
  0.250000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.125000;0.250000;;
 }
}
