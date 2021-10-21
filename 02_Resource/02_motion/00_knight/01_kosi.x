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
 25.52000;-14.79600;-2.73900;,
 6.93600;-15.14400;17.11100;,
 -0.00000;-18.08300;20.06700;,
 0.00000;-18.72400;-2.73900;,
 16.08800;-13.97100;-17.69200;,
 0.00000;-17.89800;-18.81100;,
 -25.52000;-14.79600;-2.73900;,
 -16.08800;-13.97100;-17.69200;,
 -6.93600;-15.14400;17.11100;,
 16.80000;0.79000;-1.58800;,
 4.56600;0.44300;11.47900;,
 0.00000;-2.49600;13.42500;,
 10.59100;1.61600;-11.43200;,
 0.00000;-2.31100;-12.16900;,
 -16.80000;0.79000;-1.58800;,
 -10.59100;1.61600;-11.43200;,
 -4.56600;0.44300;11.47900;;
 
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
  19;
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
   0.104000;0.104000;0.104000;1.000000;;
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
  27;
  0.000000;0.376892;0.926257;,
  0.000000;0.372439;-0.928057;,
  -0.407655;0.470109;-0.782825;,
  -0.766665;0.456060;-0.451923;,
  -0.455674;0.367913;0.810557;,
  0.407655;0.470109;-0.782825;,
  0.683674;0.336637;0.647507;,
  0.455674;0.367913;0.810557;,
  0.237861;-0.971225;-0.011997;,
  0.277763;-0.957665;0.075661;,
  0.000000;-0.996894;0.078761;,
  0.000000;-0.999924;-0.012351;,
  0.195709;-0.975597;-0.099542;,
  0.000000;-0.994835;-0.101505;,
  -0.237861;-0.971225;-0.011997;,
  -0.195709;-0.975597;-0.099542;,
  -0.277763;-0.957665;0.075661;,
  0.766665;0.456060;-0.451923;,
  -0.683674;0.336637;0.647507;,
  0.036509;0.997490;0.060671;,
  -0.157280;0.987511;0.009198;,
  -0.291898;0.956414;0.008303;,
  -0.193543;0.981033;-0.010753;,
  0.144469;0.988840;-0.036376;,
  0.305399;0.952119;-0.014141;,
  0.282512;0.958933;-0.025198;,
  -0.036509;0.997490;0.060671;;
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
