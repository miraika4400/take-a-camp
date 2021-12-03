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
 39;
 -0.15235;-0.36925;-0.54260;,
 -0.19345;-0.16215;-0.46100;,
 -0.00755;-0.16215;-0.57610;,
 -0.00755;-0.36285;-0.63200;,
 0.17825;-0.16215;-0.46100;,
 0.13715;-0.36925;-0.54260;,
 -0.00755;-0.03115;-0.32410;,
 0.13715;-0.07305;-0.31900;,
 -0.15235;-0.07305;-0.31900;,
 -0.19935;-0.01015;-0.11580;,
 -0.00755;0.01455;-0.11580;,
 0.18425;-0.01015;-0.11580;,
 -0.00755;0.00495;0.22940;,
 0.14105;-0.01345;0.13990;,
 -0.15625;-0.01345;0.13990;,
 -0.20835;-0.16215;0.15330;,
 -0.00755;-0.16215;0.25710;,
 0.19315;-0.16215;0.15330;,
 -0.00755;-0.36285;0.22940;,
 0.14105;-0.36925;0.13990;,
 -0.15625;-0.36925;0.13990;,
 -0.19345;-0.36285;-0.11580;,
 -0.00755;-0.37125;-0.11580;,
 0.17825;-0.36285;-0.11580;,
 -0.00755;-0.36285;-0.63200;,
 0.13715;-0.36925;-0.54260;,
 -0.15235;-0.36925;-0.54260;,
 0.23105;-0.16215;-0.11580;,
 0.17825;-0.36285;-0.11580;,
 0.19315;-0.16215;0.15330;,
 0.14105;-0.36925;0.13990;,
 0.18425;-0.01015;-0.11580;,
 0.14105;-0.01345;0.13990;,
 -0.15625;-0.36925;0.13990;,
 -0.20835;-0.16215;0.15330;,
 -0.24625;-0.16215;-0.11580;,
 -0.19345;-0.36285;-0.11580;,
 -0.19935;-0.01015;-0.11580;,
 -0.15625;-0.01345;0.13990;;
 
 24;
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
 4;34,38,37,35;;
 
 MeshMaterialList {
  1;
  24;
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
   0.064000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  42;
  -0.843805;0.012202;-0.536511;,
  0.843877;0.012165;-0.536398;,
  -0.487470;0.806302;-0.335037;,
  0.487598;0.806200;-0.335097;,
  -0.133358;0.990586;0.030920;,
  0.133404;0.990579;0.030945;,
  -0.801405;-0.220029;0.556180;,
  0.801478;-0.220021;0.556080;,
  -0.622576;0.777706;-0.087023;,
  0.819477;0.030453;0.572302;,
  0.000123;-0.164493;0.986378;,
  -0.819421;0.030538;0.572378;,
  0.006950;-0.999976;0.000064;,
  -0.006948;-0.999976;0.000064;,
  -0.515814;0.227022;-0.826073;,
  0.616871;0.560862;-0.552181;,
  0.000061;0.929627;-0.368502;,
  -0.616715;0.561014;-0.552201;,
  0.448748;0.878119;-0.165932;,
  0.000023;0.999513;0.031211;,
  -0.426454;0.584510;-0.690279;,
  0.000035;0.992839;-0.119463;,
  0.000125;0.024983;0.999688;,
  0.000001;-1.000000;0.000064;,
  0.996891;0.077526;-0.014051;,
  -0.996879;0.077676;-0.014060;,
  0.516050;0.226959;-0.825943;,
  0.426661;0.584461;-0.690192;,
  -0.786006;0.277135;0.552621;,
  0.000123;0.214147;0.976801;,
  0.786083;0.276955;0.552602;,
  -0.008387;-0.999961;0.002944;,
  0.000001;-0.999996;0.002945;,
  0.008390;-0.999960;0.002946;,
  0.000000;-0.999996;-0.002817;,
  0.005510;-0.999981;-0.002818;,
  -0.005510;-0.999981;-0.002817;,
  0.971332;-0.205518;-0.119488;,
  0.973121;-0.230178;0.007375;,
  0.937789;0.314454;0.147210;,
  -0.973121;-0.230178;0.007375;,
  -0.971332;-0.205518;-0.119488;;
  24;
  4;0,17,20,14;,
  4;26,27,15,1;,
  4;27,16,3,15;,
  4;17,2,16,20;,
  4;2,8,21,16;,
  4;16,21,18,3;,
  4;21,19,5,18;,
  4;8,4,19,21;,
  4;28,11,22,29;,
  4;29,22,9,30;,
  4;22,10,7,9;,
  4;11,6,10,22;,
  4;31,13,23,32;,
  4;32,23,12,33;,
  4;23,34,35,12;,
  4;13,36,34,23;,
  4;1,37,24,38;,
  4;38,24,9,7;,
  4;24,39,30,9;,
  4;15,3,18,24;,
  4;6,11,25,40;,
  4;40,25,41,0;,
  4;25,8,2,17;,
  4;11,28,8,25;;
 }
 MeshTextureCoords {
  39;
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
