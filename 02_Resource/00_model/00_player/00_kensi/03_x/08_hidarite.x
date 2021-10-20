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
 117;
 0.91833;-0.29806;-0.03437;,
 0.92251;-0.07010;0.04904;,
 0.77672;-0.07010;-0.21292;,
 0.80914;-0.37785;-0.22786;,
 0.69577;-0.07010;-0.50475;,
 0.75038;-0.29806;-0.44458;,
 0.80914;0.23765;-0.22786;,
 0.75038;0.15786;-0.44458;,
 0.91833;0.15786;-0.03437;,
 1.01976;0.23765;0.00422;,
 0.90640;0.34024;-0.27267;,
 0.79303;0.23765;-0.54957;,
 1.00365;0.23765;-0.31749;,
 0.89446;0.15786;-0.51098;,
 1.06241;0.15786;-0.10076;,
 1.11702;-0.07010;-0.04059;,
 1.03607;-0.07010;-0.33243;,
 0.89028;-0.07010;-0.59438;,
 1.00365;-0.37785;-0.31749;,
 0.89446;-0.29806;-0.51098;,
 1.06241;-0.29806;-0.10076;,
 1.01976;-0.37785;0.00422;,
 0.90640;-0.48044;-0.27267;,
 0.79303;-0.37785;-0.54957;,
 0.80914;-0.37785;-0.22786;,
 0.75038;-0.29806;-0.44458;,
 0.91833;-0.29806;-0.03437;,
 0.75524;-0.07010;-0.64186;,
 0.79303;-0.37785;-0.54957;,
 0.89028;-0.07010;-0.59438;,
 0.89446;-0.29806;-0.51098;,
 0.79303;0.23765;-0.54957;,
 0.89446;0.15786;-0.51098;,
 1.06241;-0.29806;-0.10076;,
 1.11702;-0.07010;-0.04059;,
 1.05755;-0.07010;0.09652;,
 1.01976;-0.37785;0.00422;,
 1.01976;0.23765;0.00422;,
 1.06241;0.15786;-0.10076;,
 0.36431;-0.46211;-0.12398;,
 0.26436;-0.09521;-0.16182;,
 0.63528;-0.09521;-0.23034;,
 0.63893;-0.59053;-0.17672;,
 1.01350;-0.09521;-0.19161;,
 0.91923;-0.46211;-0.14604;,
 0.63893;0.40012;-0.17672;,
 0.91923;0.27170;-0.14604;,
 0.36431;0.27170;-0.12398;,
 0.27531;0.40012;-0.00096;,
 0.64988;0.56522;-0.01585;,
 1.02446;0.40012;-0.03074;,
 0.66084;0.40012;0.14502;,
 0.93546;0.27170;0.09228;,
 0.38054;0.27170;0.11435;,
 0.28627;-0.09521;0.15991;,
 0.66449;-0.09521;0.19864;,
 1.03541;-0.09521;0.13013;,
 0.66084;-0.59053;0.14502;,
 0.93546;-0.46211;0.09228;,
 0.38054;-0.46211;0.11435;,
 0.27531;-0.59053;-0.00096;,
 0.64988;-0.75564;-0.01585;,
 1.02446;-0.59053;-0.03074;,
 0.63893;-0.59053;-0.17672;,
 0.91923;-0.46211;-0.14604;,
 0.36431;-0.46211;-0.12398;,
 1.14932;-0.09521;-0.03570;,
 1.02446;-0.59053;-0.03074;,
 1.03541;-0.09521;0.13013;,
 0.93546;-0.46211;0.09228;,
 1.02446;0.40012;-0.03074;,
 0.93546;0.27170;0.09228;,
 0.38054;-0.46211;0.11435;,
 0.28627;-0.09521;0.15991;,
 0.15046;-0.09521;0.00401;,
 0.27531;-0.59053;-0.00096;,
 0.27531;0.40012;-0.00096;,
 0.38054;0.27170;0.11435;,
 0.03287;-0.25761;-0.19211;,
 -0.01597;-0.08506;-0.25250;,
 0.17244;-0.08506;-0.33015;,
 0.17244;-0.31801;-0.25250;,
 0.36085;-0.08506;-0.25250;,
 0.31200;-0.25761;-0.19211;,
 0.17244;0.14788;-0.25250;,
 0.31200;0.08748;-0.19211;,
 0.03287;0.08748;-0.19211;,
 -0.01597;0.14788;-0.01956;,
 0.17244;0.22552;-0.01956;,
 0.36085;0.14788;-0.01956;,
 0.17244;0.14788;0.21338;,
 0.31200;0.08748;0.15299;,
 0.03287;0.08748;0.15299;,
 -0.01597;-0.08506;0.21338;,
 0.17244;-0.08506;0.29102;,
 0.36085;-0.08506;0.21338;,
 0.17244;-0.31801;0.21338;,
 0.31200;-0.25761;0.15299;,
 0.03287;-0.25761;0.15299;,
 -0.01597;-0.31801;-0.01956;,
 0.17244;-0.39565;-0.01956;,
 0.36085;-0.31801;-0.01956;,
 0.17244;-0.31801;-0.25250;,
 0.31200;-0.25761;-0.19211;,
 0.03287;-0.25761;-0.19211;,
 0.42366;-0.08506;-0.01956;,
 0.36085;-0.31801;-0.01956;,
 0.36085;-0.08506;0.21338;,
 0.31200;-0.25761;0.15299;,
 0.36085;0.14788;-0.01956;,
 0.31200;0.08748;0.15299;,
 0.03287;-0.25761;0.15299;,
 -0.01597;-0.08506;0.21338;,
 -0.07878;-0.08506;-0.01956;,
 -0.01597;-0.31801;-0.01956;,
 -0.01597;0.14788;-0.01956;,
 0.03287;0.08748;0.15299;;
 
 72;
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
 4;73,77,76,74;,
 4;78,79,80,81;,
 4;81,80,82,83;,
 4;80,84,85,82;,
 4;79,86,84,80;,
 4;86,87,88,84;,
 4;84,88,89,85;,
 4;88,90,91,89;,
 4;87,92,90,88;,
 4;92,93,94,90;,
 4;90,94,95,91;,
 4;94,96,97,95;,
 4;93,98,96,94;,
 4;98,99,100,96;,
 4;96,100,101,97;,
 4;100,102,103,101;,
 4;99,104,102,100;,
 4;83,82,105,106;,
 4;106,105,107,108;,
 4;105,109,110,107;,
 4;82,85,109,105;,
 4;111,112,113,114;,
 4;114,113,79,78;,
 4;113,115,86,79;,
 4;112,116,115,113;;
 
 MeshMaterialList {
  12;
  72;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
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
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  94;
  -0.642419;-0.367907;0.672267;,
  -0.933515;-0.358307;-0.012881;,
  -0.642420;0.367905;0.672267;,
  -0.933515;0.358306;-0.012881;,
  0.933516;0.358304;0.012880;,
  0.642419;0.367905;-0.672268;,
  0.933515;-0.358306;0.012880;,
  0.642418;-0.367907;-0.672267;,
  -0.500508;0.469584;0.727312;,
  0.672055;0.000000;-0.740501;,
  0.842083;-0.413254;-0.346579;,
  0.999319;0.000000;0.036903;,
  0.500506;-0.469586;-0.727312;,
  0.877254;-0.457647;0.144862;,
  -0.842083;-0.413255;0.346578;,
  -0.999319;0.000000;-0.036904;,
  -0.842084;0.413253;0.346579;,
  -0.672056;0.000000;0.740501;,
  -0.877254;0.457647;-0.144862;,
  0.842084;0.413252;-0.346580;,
  -0.925108;0.000000;0.379704;,
  -0.693707;0.660792;0.286575;,
  0.925108;0.000000;-0.379704;,
  0.693704;-0.660795;-0.286574;,
  -0.946658;0.000000;-0.322239;,
  0.946659;0.000000;0.322238;,
  -0.464929;-0.330765;-0.821240;,
  0.388754;-0.332768;-0.859148;,
  -0.464929;0.330766;-0.821240;,
  0.388754;0.332768;-0.859148;,
  -0.388755;0.332769;0.859148;,
  0.464929;0.330766;0.821240;,
  -0.388755;-0.332768;0.859148;,
  0.464929;-0.330765;0.821240;,
  -0.575177;0.419501;-0.702275;,
  0.517128;-0.000000;0.855908;,
  0.038209;-0.385842;0.921773;,
  -0.433399;-0.000000;0.901202;,
  0.575176;-0.419500;0.702276;,
  -0.505000;-0.423492;0.752083;,
  -0.038208;-0.385843;-0.921773;,
  0.433397;-0.000000;-0.901203;,
  -0.038208;0.385844;-0.921773;,
  -0.517129;-0.000000;-0.855907;,
  0.504998;0.423493;-0.752085;,
  0.038209;0.385843;0.921773;,
  -0.040541;-0.000000;-0.999178;,
  -0.033259;0.624149;-0.780597;,
  0.040543;-0.000000;0.999178;,
  0.033260;-0.624146;0.780600;,
  0.697664;-0.000000;-0.716425;,
  -0.697670;-0.000000;0.716420;,
  -0.640814;-0.542843;-0.542843;,
  0.640812;-0.542844;-0.542844;,
  -0.640813;0.542845;-0.542843;,
  0.640811;0.542846;-0.542844;,
  -0.640813;0.542845;0.542843;,
  0.640811;0.542846;0.542844;,
  -0.640814;-0.542843;0.542844;,
  0.640812;-0.542844;0.542844;,
  -0.758822;0.651298;-0.000001;,
  0.758822;0.000000;0.651298;,
  0.000000;-0.707106;0.707107;,
  -0.758823;0.000000;0.651297;,
  0.758822;-0.651298;-0.000001;,
  -0.758824;-0.651296;-0.000001;,
  0.000000;-0.707107;-0.707107;,
  0.758822;0.000000;-0.651298;,
  0.000000;0.707109;-0.707105;,
  -0.758824;0.000000;-0.651296;,
  0.758820;0.651300;-0.000001;,
  0.000000;0.707108;0.707105;,
  0.000000;0.000000;-1.000000;,
  0.000000;1.000000;-0.000001;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;-0.000001;,
  1.000000;-0.000000;-0.000001;,
  -1.000000;0.000000;-0.000001;,
  0.693708;0.660791;-0.286576;,
  0.500507;0.469583;-0.727313;,
  0.877255;0.457644;0.144862;,
  -0.693703;-0.660796;0.286573;,
  -0.877253;-0.457649;-0.144863;,
  -0.500506;-0.469586;0.727312;,
  0.413774;0.000000;-0.910380;,
  -0.413774;0.000000;0.910380;,
  0.033260;0.624148;0.780598;,
  0.575176;0.419501;0.702275;,
  -0.505000;0.423493;0.752083;,
  -0.033259;-0.624147;-0.780599;,
  0.504998;-0.423492;-0.752085;,
  -0.575177;-0.419500;-0.702276;,
  0.772104;-0.000000;0.635497;,
  -0.772105;-0.000000;-0.635495;;
  72;
  4;0,17,20,14;,
  4;14,20,15,1;,
  4;20,16,3,15;,
  4;17,2,16,20;,
  4;2,8,21,16;,
  4;16,21,18,3;,
  4;78,19,5,79;,
  4;80,4,19,78;,
  4;4,11,22,19;,
  4;19,22,9,5;,
  4;22,10,7,9;,
  4;11,6,10,22;,
  4;6,13,23,10;,
  4;10,23,12,7;,
  4;81,14,1,82;,
  4;83,0,14,81;,
  4;1,15,24,82;,
  4;12,84,9,7;,
  4;84,79,5,9;,
  4;15,3,18,24;,
  4;6,11,25,13;,
  4;83,85,17,0;,
  4;85,8,2,17;,
  4;11,4,80,25;,
  4;26,43,46,40;,
  4;40,46,41,27;,
  4;46,42,29,41;,
  4;43,28,42,46;,
  4;28,34,47,42;,
  4;42,47,44,29;,
  4;86,45,31,87;,
  4;88,30,45,86;,
  4;30,37,48,45;,
  4;45,48,35,31;,
  4;48,36,33,35;,
  4;37,32,36,48;,
  4;32,39,49,36;,
  4;36,49,38,33;,
  4;89,40,27,90;,
  4;91,26,40,89;,
  4;27,41,50,90;,
  4;38,92,35,33;,
  4;92,87,31,35;,
  4;41,29,44,50;,
  4;32,37,51,39;,
  4;91,93,43,26;,
  4;93,34,28,43;,
  4;37,30,88,51;,
  4;52,69,72,66;,
  4;66,72,67,53;,
  4;72,68,55,67;,
  4;69,54,68,72;,
  4;54,60,73,68;,
  4;68,73,70,55;,
  4;73,71,57,70;,
  4;60,56,71,73;,
  4;56,63,74,71;,
  4;71,74,61,57;,
  4;74,62,59,61;,
  4;63,58,62,74;,
  4;58,65,75,62;,
  4;62,75,64,59;,
  4;75,66,53,64;,
  4;65,52,66,75;,
  4;53,67,76,64;,
  4;64,76,61,59;,
  4;76,70,57,61;,
  4;67,55,70,76;,
  4;58,63,77,65;,
  4;65,77,69,52;,
  4;77,60,54,69;,
  4;63,56,60,77;;
 }
 MeshTextureCoords {
  117;
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
