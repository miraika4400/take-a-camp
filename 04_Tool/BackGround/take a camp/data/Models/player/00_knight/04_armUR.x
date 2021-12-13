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
 -1.30553;-0.17584;-0.13300;,
 -1.46963;0.02046;-0.20170;,
 -0.83653;0.02046;-0.29000;,
 -0.83653;-0.24454;-0.20170;,
 -0.20343;0.02046;-0.20170;,
 -0.36753;-0.17584;-0.13300;,
 -0.83653;0.28536;-0.20170;,
 -0.36753;0.21666;-0.13300;,
 -1.30553;0.21666;-0.13300;,
 -1.46963;0.28536;0.06330;,
 -0.83653;0.37376;0.06330;,
 -0.20343;0.28536;0.06330;,
 -0.83653;0.28536;0.32830;,
 -0.36753;0.21666;0.25960;,
 -1.30553;0.21666;0.25960;,
 -1.46963;0.02046;0.32830;,
 -0.83653;0.02046;0.41660;,
 -0.20343;0.02046;0.32830;,
 -0.83653;-0.24454;0.32830;,
 -0.36753;-0.17584;0.25960;,
 -1.30553;-0.17584;0.25960;,
 -1.46963;-0.24454;0.06330;,
 -0.83653;-0.33294;0.06330;,
 -0.20343;-0.24454;0.06330;,
 -0.83653;-0.24454;-0.20170;,
 -0.36753;-0.17584;-0.13300;,
 -1.30553;-0.17584;-0.13300;,
 0.00757;0.02046;0.06330;,
 -0.20343;-0.24454;0.06330;,
 -0.20343;0.02046;0.32830;,
 -0.36753;-0.17584;0.25960;,
 -0.20343;0.28536;0.06330;,
 -0.36753;0.21666;0.25960;,
 -1.30553;-0.17584;0.25960;,
 -1.46963;0.02046;0.32830;,
 -1.68063;0.02046;0.06330;,
 -1.46963;-0.24454;0.06330;,
 -1.46963;0.28536;0.06330;,
 -1.30553;0.21666;0.25960;;
 
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
  32;
  -0.318576;-0.670212;-0.670318;,
  0.318576;-0.670212;-0.670318;,
  -0.318527;0.670298;-0.670255;,
  0.318527;0.670298;-0.670254;,
  -0.318527;0.670298;0.670254;,
  0.318527;0.670298;0.670254;,
  -0.318576;-0.670211;0.670318;,
  0.318576;-0.670212;0.670318;,
  -0.438906;0.898533;0.000000;,
  0.438922;0.000092;0.898525;,
  -0.000000;-0.707026;0.707188;,
  -0.438922;0.000092;0.898525;,
  0.438996;-0.898489;-0.000000;,
  -0.438996;-0.898489;0.000000;,
  -0.000000;-0.707026;-0.707188;,
  0.438922;0.000092;-0.898525;,
  -0.000000;0.707080;-0.707133;,
  -0.438922;0.000092;-0.898525;,
  0.438906;0.898533;0.000000;,
  -0.000000;0.707080;0.707133;,
  -0.000000;0.000078;-1.000000;,
  -0.000000;1.000000;0.000000;,
  -0.000000;0.000078;1.000000;,
  -0.000000;-1.000000;0.000000;,
  0.576509;-0.577770;-0.577771;,
  -0.576509;-0.577770;0.577771;,
  0.576509;-0.577770;0.577771;,
  0.576401;0.577933;0.577715;,
  0.576401;0.577933;-0.577715;,
  -0.576509;-0.577770;-0.577771;,
  -0.576401;0.577933;-0.577715;,
  -0.576401;0.577933;0.577715;;
  24;
  4;0,17,20,14;,
  4;14,20,15,1;,
  4;20,16,3,15;,
  4;17,2,16,20;,
  4;2,8,21,16;,
  4;16,21,18,3;,
  4;21,19,5,18;,
  4;8,4,19,21;,
  4;4,11,22,19;,
  4;19,22,9,5;,
  4;22,10,7,9;,
  4;11,6,10,22;,
  4;6,13,23,10;,
  4;10,23,12,7;,
  4;23,14,1,12;,
  4;13,0,14,23;,
  4;1,15,24,12;,
  4;12,26,9,7;,
  4;27,18,5,9;,
  4;15,3,18,28;,
  4;6,11,25,13;,
  4;13,29,17,0;,
  4;30,8,2,17;,
  4;11,4,8,31;;
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
