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
 -0.12573;-0.34089;-0.45650;,
 -0.16233;-0.15649;-0.38390;,
 0.00327;-0.15649;-0.48640;,
 0.00327;-0.33529;-0.53620;,
 0.16877;-0.15649;-0.38390;,
 0.13217;-0.34089;-0.45650;,
 0.00327;-0.03969;-0.26190;,
 0.13217;-0.07709;-0.25740;,
 -0.12573;-0.07709;-0.25740;,
 -0.16763;-0.02109;-0.07640;,
 0.00327;0.00091;-0.07640;,
 0.17407;-0.02109;-0.07640;,
 0.00327;-0.00759;0.23110;,
 0.13567;-0.02409;0.15130;,
 -0.12923;-0.02409;0.15130;,
 -0.17553;-0.15649;0.16330;,
 0.00327;-0.15649;0.25580;,
 0.18207;-0.15649;0.16330;,
 0.00327;-0.33529;0.23110;,
 0.13567;-0.34089;0.15130;,
 -0.12923;-0.34089;0.15130;,
 -0.16233;-0.33529;-0.07640;,
 0.00327;-0.34269;-0.07640;,
 0.16877;-0.33529;-0.07640;,
 0.00327;-0.33529;-0.53620;,
 0.13217;-0.34089;-0.45650;,
 -0.12573;-0.34089;-0.45650;,
 0.21587;-0.15649;-0.07640;,
 0.16877;-0.33529;-0.07640;,
 0.18207;-0.15649;0.16330;,
 0.13567;-0.34089;0.15130;,
 0.17407;-0.02109;-0.07640;,
 0.13567;-0.02409;0.15130;,
 -0.12923;-0.34089;0.15130;,
 -0.17553;-0.15649;0.16330;,
 -0.20933;-0.15649;-0.07640;,
 -0.16233;-0.33529;-0.07640;,
 -0.16763;-0.02109;-0.07640;,
 -0.12923;-0.02409;0.15130;;
 
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
  13;
  24;
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
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
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
  42;
  -0.843815;0.012181;-0.536496;,
  0.843849;0.011999;-0.536447;,
  -0.487698;0.806173;-0.335016;,
  0.487650;0.806199;-0.335023;,
  -0.133673;0.990541;0.030971;,
  0.133761;0.990529;0.030977;,
  -0.801512;-0.219910;0.556073;,
  0.801485;-0.220237;0.555984;,
  -0.622862;0.777494;-0.086870;,
  0.819536;0.030532;0.572214;,
  0.000078;-0.164715;0.986341;,
  -0.819509;0.030480;0.572256;,
  0.007027;-0.999975;0.000078;,
  -0.007026;-0.999975;0.000077;,
  -0.515832;0.226910;-0.826093;,
  0.616855;0.560838;-0.552223;,
  0.000078;0.929639;-0.368471;,
  -0.616856;0.560778;-0.552283;,
  0.448851;0.878095;-0.165776;,
  0.000045;0.999511;0.031254;,
  -0.426524;0.584347;-0.690373;,
  0.000058;0.992860;-0.119284;,
  0.000079;0.025009;0.999687;,
  0.000001;-1.000000;0.000077;,
  0.996883;0.077626;-0.014076;,
  -0.996892;0.077530;-0.013973;,
  0.516097;0.226839;-0.825947;,
  0.426758;0.584292;-0.690275;,
  -0.786143;0.276904;0.552543;,
  0.000076;0.214420;0.976741;,
  0.786066;0.277322;0.552442;,
  -0.008449;-0.999960;0.002989;,
  0.000001;-0.999996;0.002990;,
  0.008452;-0.999960;0.002991;,
  0.000000;-0.999996;-0.002835;,
  0.005603;-0.999980;-0.002836;,
  -0.005602;-0.999980;-0.002834;,
  0.971281;-0.205690;-0.119601;,
  0.973076;-0.230369;0.007354;,
  0.937653;0.314878;0.147167;,
  -0.973164;-0.229992;0.007439;,
  -0.971352;-0.205441;-0.119456;;
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
