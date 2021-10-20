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
 17;
 2.55197;-1.47964;-0.27389;,
 0.69358;-1.51439;1.71108;,
 -0.00000;-1.80828;2.00673;,
 -0.00000;-1.87237;-0.27389;,
 1.60879;-1.39705;-1.76923;,
 -0.00000;-1.78978;-1.88110;,
 -2.55197;-1.47964;-0.27389;,
 -1.60879;-1.39705;-1.76924;,
 -0.69359;-1.51439;1.71109;,
 1.67995;0.07900;-0.15883;,
 0.45659;0.04425;1.14787;,
 0.00000;-0.24964;1.34248;,
 1.05907;0.16159;-1.14322;,
 0.00000;-0.23114;-1.21685;,
 -1.67995;0.07900;-0.15883;,
 -1.05907;0.16159;-1.14322;,
 -0.45659;0.04425;1.14787;;
 
 18;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;3,6,7,5;,
 4;2,8,6,3;,
 4;9,10,1,0;,
 4;10,11,2,1;,
 4;12,9,0,4;,
 4;13,12,4,5;,
 4;14,15,7,6;,
 4;15,13,5,7;,
 4;11,16,8,2;,
 4;16,14,6,8;,
 3;9,12,10;,
 3;12,13,10;,
 3;10,13,11;,
 3;13,15,11;,
 3;11,15,16;,
 3;15,14,16;;
 
 MeshMaterialList {
  3;
  18;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
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
 }
 MeshNormals {
  27;
  0.000002;0.376920;0.926246;,
  0.000001;0.372457;-0.928049;,
  -0.407635;0.470134;-0.782820;,
  -0.766671;0.456071;-0.451901;,
  -0.455685;0.367935;0.810540;,
  0.407636;0.470132;-0.782821;,
  0.683672;0.336654;0.647501;,
  0.455686;0.367933;0.810540;,
  0.237853;-0.971227;-0.012004;,
  0.277753;-0.957668;0.075661;,
  0.000000;-0.996894;0.078760;,
  0.000000;-0.999924;-0.012359;,
  0.195703;-0.975597;-0.099556;,
  -0.000000;-0.994834;-0.101519;,
  -0.237853;-0.971227;-0.012004;,
  -0.195704;-0.975597;-0.099556;,
  -0.277752;-0.957669;0.075661;,
  0.766670;0.456071;-0.451902;,
  -0.683672;0.336656;0.647499;,
  0.036479;0.997491;0.060676;,
  -0.157312;0.987506;0.009205;,
  -0.291920;0.956407;0.008308;,
  -0.193547;0.981032;-0.010750;,
  0.144480;0.988839;-0.036370;,
  0.305420;0.952113;-0.014134;,
  0.282529;0.958928;-0.025187;,
  -0.036479;0.997491;0.060676;;
  18;
  4;8,9,10,11;,
  4;12,8,11,13;,
  4;11,14,15,13;,
  4;10,16,14,11;,
  4;6,7,7,6;,
  4;7,0,0,7;,
  4;5,17,17,5;,
  4;1,5,5,1;,
  4;3,2,2,3;,
  4;2,1,1,2;,
  4;0,4,4,0;,
  4;4,18,18,4;,
  3;19,20,21;,
  3;20,22,21;,
  3;21,22,23;,
  3;22,24,23;,
  3;23,24,25;,
  3;24,26,25;;
 }
 MeshTextureCoords {
  17;
  0.437500;0.875000;,
  0.437500;0.750000;,
  0.500000;0.750000;,
  0.500000;0.875000;,
  0.437500;1.000000;,
  0.500000;1.000000;,
  0.562500;0.875000;,
  0.562500;1.000000;,
  0.562500;0.750000;,
  0.437500;0.875000;,
  0.437500;0.750000;,
  0.500000;0.750000;,
  0.437500;1.000000;,
  0.500000;1.000000;,
  0.562500;0.875000;,
  0.562500;1.000000;,
  0.562500;0.750000;;
 }
}
