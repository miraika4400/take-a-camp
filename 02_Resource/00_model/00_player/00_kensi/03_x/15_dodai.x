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
 84;
 -4.76510;-0.01023;1.54664;,
 -4.05490;-0.01023;2.94049;,
 -3.52107;1.90977;2.55264;,
 -4.13755;1.90977;1.34274;,
 -2.94874;-0.01023;4.04664;,
 -2.56089;1.90977;3.51281;,
 -1.55490;-0.01023;4.75684;,
 -1.35100;1.90977;4.12929;,
 -0.00981;-0.01023;5.00156;,
 -0.00982;1.90977;4.34171;,
 1.53527;-0.01023;4.75684;,
 1.33137;1.90977;4.12929;,
 2.92911;-0.01023;4.04664;,
 2.54126;1.90977;3.51281;,
 4.03527;-0.01023;2.94048;,
 3.50144;1.90977;2.55263;,
 4.74547;-0.01023;1.54664;,
 4.11791;1.90977;1.34274;,
 4.99019;-0.01023;0.00156;,
 4.33034;1.90977;0.00156;,
 4.74547;-0.01023;-1.54353;,
 4.11791;1.90977;-1.33962;,
 4.03527;-0.01023;-2.93737;,
 3.50144;1.90977;-2.54952;,
 2.92911;-0.01023;-4.04353;,
 2.54126;1.90977;-3.50970;,
 1.53527;-0.01023;-4.75373;,
 1.33137;1.90977;-4.12617;,
 -0.00981;-0.01023;-4.99844;,
 -0.00982;1.90977;-4.33859;,
 -1.55490;-0.01023;-4.75372;,
 -1.35100;1.90977;-4.12617;,
 -2.94874;-0.01023;-4.04353;,
 -2.56089;1.90977;-3.50970;,
 -4.05490;-0.01023;-2.93737;,
 -3.52107;1.90977;-2.54952;,
 -4.76510;-0.01023;-1.54353;,
 -4.13754;1.90977;-1.33962;,
 -5.00981;-0.01023;0.00156;,
 -4.34997;1.90977;0.00156;,
 -4.76510;-0.01023;1.54664;,
 -4.13755;1.90977;1.34274;,
 -4.05490;-0.01023;2.94049;,
 -4.76510;-0.01023;1.54664;,
 -0.00982;-0.01023;0.00156;,
 -2.94874;-0.01023;4.04664;,
 -1.55490;-0.01023;4.75684;,
 -0.00981;-0.01023;5.00156;,
 1.53527;-0.01023;4.75684;,
 2.92911;-0.01023;4.04664;,
 4.03527;-0.01023;2.94048;,
 4.74547;-0.01023;1.54664;,
 4.99019;-0.01023;0.00156;,
 4.74547;-0.01023;-1.54353;,
 4.03527;-0.01023;-2.93737;,
 2.92911;-0.01023;-4.04353;,
 1.53527;-0.01023;-4.75373;,
 -0.00981;-0.01023;-4.99844;,
 -1.55490;-0.01023;-4.75372;,
 -2.94874;-0.01023;-4.04353;,
 -4.05490;-0.01023;-2.93737;,
 -4.76510;-0.01023;-1.54353;,
 -5.00981;-0.01023;0.00156;,
 -4.13755;1.90977;1.34274;,
 -3.52107;1.90977;2.55264;,
 -0.00982;1.90977;0.00156;,
 -2.56089;1.90977;3.51281;,
 -1.35100;1.90977;4.12929;,
 -0.00982;1.90977;4.34171;,
 1.33137;1.90977;4.12929;,
 2.54126;1.90977;3.51281;,
 3.50144;1.90977;2.55263;,
 4.11791;1.90977;1.34274;,
 4.33034;1.90977;0.00156;,
 4.11791;1.90977;-1.33962;,
 3.50144;1.90977;-2.54952;,
 2.54126;1.90977;-3.50970;,
 1.33137;1.90977;-4.12617;,
 -0.00982;1.90977;-4.33859;,
 -1.35100;1.90977;-4.12617;,
 -2.56089;1.90977;-3.50970;,
 -3.52107;1.90977;-2.54952;,
 -4.13754;1.90977;-1.33962;,
 -4.34997;1.90977;0.00156;;
 
 60;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;16,18,19,17;,
 4;18,20,21,19;,
 4;20,22,23,21;,
 4;22,24,25,23;,
 4;24,26,27,25;,
 4;26,28,29,27;,
 4;28,30,31,29;,
 4;30,32,33,31;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 3;42,43,44;,
 3;45,42,44;,
 3;46,45,44;,
 3;47,46,44;,
 3;48,47,44;,
 3;49,48,44;,
 3;50,49,44;,
 3;51,50,44;,
 3;52,51,44;,
 3;53,52,44;,
 3;54,53,44;,
 3;55,54,44;,
 3;56,55,44;,
 3;57,56,44;,
 3;58,57,44;,
 3;59,58,44;,
 3;60,59,44;,
 3;61,60,44;,
 3;62,61,44;,
 3;43,62,44;,
 3;63,64,65;,
 3;64,66,65;,
 3;66,67,65;,
 3;67,68,65;,
 3;68,69,65;,
 3;69,70,65;,
 3;70,71,65;,
 3;71,72,65;,
 3;72,73,65;,
 3;73,74,65;,
 3;74,75,65;,
 3;75,76,65;,
 3;76,77,65;,
 3;77,78,65;,
 3;78,79,65;,
 3;79,80,65;,
 3;80,81,65;,
 3;81,82,65;,
 3;82,83,65;,
 3;83,63,65;;
 
 MeshMaterialList {
  1;
  60;
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
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  22;
  -0.899423;0.325014;0.292240;,
  -0.765095;0.325014;0.555874;,
  -0.555874;0.325014;0.765095;,
  -0.292240;0.325014;0.899423;,
  0.000000;0.325014;0.945709;,
  0.292240;0.325014;0.899423;,
  0.555874;0.325013;0.765095;,
  0.765095;0.325013;0.555874;,
  0.899423;0.325013;0.292240;,
  0.945709;0.325013;0.000000;,
  0.899423;0.325013;-0.292240;,
  0.765095;0.325013;-0.555874;,
  0.555874;0.325013;-0.765095;,
  0.292240;0.325013;-0.899423;,
  -0.000000;0.325013;-0.945709;,
  -0.292240;0.325013;-0.899423;,
  -0.555874;0.325013;-0.765095;,
  -0.765095;0.325013;-0.555874;,
  -0.899423;0.325014;-0.292240;,
  -0.945709;0.325014;-0.000001;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;;
  60;
  4;0,1,1,0;,
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;10,11,11,10;,
  4;11,12,12,11;,
  4;12,13,13,12;,
  4;13,14,14,13;,
  4;14,15,15,14;,
  4;15,16,16,15;,
  4;16,17,17,16;,
  4;17,18,18,17;,
  4;18,19,19,18;,
  4;19,0,0,19;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;,
  3;21,21,21;;
 }
 MeshTextureCoords {
  84;
  0.375000;0.312500;,
  0.387500;0.312500;,
  0.387500;0.688440;,
  0.375000;0.688440;,
  0.400000;0.312500;,
  0.400000;0.688440;,
  0.412500;0.312500;,
  0.412500;0.688440;,
  0.425000;0.312500;,
  0.425000;0.688440;,
  0.437500;0.312500;,
  0.437500;0.688440;,
  0.450000;0.312500;,
  0.450000;0.688440;,
  0.462500;0.312500;,
  0.462500;0.688440;,
  0.475000;0.312500;,
  0.475000;0.688440;,
  0.487500;0.312500;,
  0.487500;0.688440;,
  0.500000;0.312500;,
  0.500000;0.688440;,
  0.512500;0.312500;,
  0.512500;0.688440;,
  0.525000;0.312500;,
  0.525000;0.688440;,
  0.537500;0.312500;,
  0.537500;0.688440;,
  0.550000;0.312500;,
  0.550000;0.688440;,
  0.562500;0.312500;,
  0.562500;0.688440;,
  0.575000;0.312500;,
  0.575000;0.688440;,
  0.587500;0.312500;,
  0.587500;0.688440;,
  0.600000;0.312500;,
  0.600000;0.688440;,
  0.612500;0.312500;,
  0.612500;0.688440;,
  0.625000;0.312500;,
  0.625000;0.688440;,
  0.626409;0.064408;,
  0.648603;0.107966;,
  0.500000;0.150000;,
  0.591842;0.029841;,
  0.548284;0.007647;,
  0.500000;-0.000000;,
  0.451716;0.007647;,
  0.408159;0.029841;,
  0.373591;0.064409;,
  0.351397;0.107966;,
  0.343750;0.156250;,
  0.351397;0.204534;,
  0.373591;0.248091;,
  0.408159;0.282659;,
  0.451716;0.304853;,
  0.500000;0.312500;,
  0.548284;0.304853;,
  0.591841;0.282659;,
  0.626409;0.248091;,
  0.648603;0.204534;,
  0.656250;0.156250;,
  0.648603;0.892034;,
  0.626409;0.935591;,
  0.500000;0.837500;,
  0.591841;0.970159;,
  0.548284;0.992353;,
  0.500000;1.000000;,
  0.451716;0.992353;,
  0.408159;0.970159;,
  0.373591;0.935591;,
  0.351397;0.892034;,
  0.343750;0.843750;,
  0.351397;0.795466;,
  0.373591;0.751909;,
  0.408159;0.717341;,
  0.451716;0.695147;,
  0.500000;0.687500;,
  0.548284;0.695147;,
  0.591842;0.717341;,
  0.626409;0.751908;,
  0.648603;0.795466;,
  0.656250;0.843750;;
 }
}
