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
 156;
 -2.32400;-2.62100;-2.20300;,
 -3.10600;-0.38700;-2.98400;,
 -0.09000;-0.38700;-3.99000;,
 -0.09000;-3.40300;-2.98400;,
 2.92500;-0.38700;-2.98400;,
 2.14400;-2.62100;-2.20300;,
 -0.09000;2.62900;-2.98400;,
 2.14400;1.84700;-2.20300;,
 -2.32400;1.84700;-2.20300;,
 -3.10600;2.62900;0.03100;,
 -0.09000;3.63400;0.03100;,
 2.92500;2.62900;0.03100;,
 -0.09000;2.62900;3.04700;,
 2.14400;1.84700;2.26500;,
 -2.32400;1.84700;2.26500;,
 -3.10600;-0.38700;3.04700;,
 -0.09000;-0.38700;4.05200;,
 2.92500;-0.38700;3.04700;,
 -0.09000;-3.40300;3.04700;,
 2.14400;-2.62100;2.26500;,
 -2.32400;-2.62100;2.26500;,
 -3.10600;-3.40300;0.03100;,
 -0.09000;-4.40800;0.03100;,
 2.92500;-3.40300;0.03100;,
 -0.09000;-3.40300;-2.98400;,
 2.14400;-2.62100;-2.20300;,
 -2.32400;-2.62100;-2.20300;,
 3.93100;-0.38700;0.03100;,
 2.92500;-3.40300;0.03100;,
 2.92500;-0.38700;3.04700;,
 2.14400;-2.62100;2.26500;,
 2.92500;2.62900;0.03100;,
 2.14400;1.84700;2.26500;,
 -2.32400;-2.62100;2.26500;,
 -3.10600;-0.38700;3.04700;,
 -4.11100;-0.38700;0.03100;,
 -3.10600;-3.40300;0.03100;,
 -3.10600;2.62900;0.03100;,
 -2.32400;1.84700;2.26500;,
 21.43200;4.35800;3.09900;,
 21.14900;5.33100;-0.76100;,
 12.97900;5.10400;-0.51300;,
 13.26200;4.13100;3.34700;,
 20.93500;-4.66600;3.88200;,
 12.73200;-4.44300;4.11200;,
 12.48200;-6.86200;-0.00900;,
 20.70100;-6.87100;-0.24800;,
 20.70100;-6.87000;-0.23500;,
 12.48200;-6.86100;0.00400;,
 12.56900;-5.11100;-4.29900;,
 20.77300;-5.33500;-4.52900;,
 29.54100;3.96300;2.87800;,
 29.47600;4.93700;-0.98800;,
 29.07300;-5.33300;3.15900;,
 28.94900;-6.67600;-0.49700;,
 28.94900;-6.67500;-0.48400;,
 28.93100;-5.92100;-4.23000;,
 13.11500;3.52500;-4.27900;,
 21.28500;3.75200;-4.52700;,
 29.39400;3.35700;-4.74700;,
 4.48400;-4.65500;3.80700;,
 4.41100;-5.31600;0.16300;,
 4.72100;3.75700;-0.21600;,
 4.78500;2.78300;3.65000;,
 4.63800;2.17700;-3.97600;,
 4.41100;-5.31500;0.17600;,
 4.34300;-5.23600;-3.49900;,
 37.57600;2.51400;-1.16500;,
 37.46400;1.50000;-4.00200;,
 37.57600;1.34800;1.82300;,
 37.29000;-4.55000;2.15600;,
 37.21900;-6.06500;-0.76400;,
 37.21900;-6.06400;-0.75100;,
 37.15400;-5.12200;-3.56000;,
 29.41200;-0.97400;5.44000;,
 37.59700;-1.23200;3.46400;,
 21.21000;-0.78600;5.67100;,
 13.00800;-0.59900;5.90300;,
 4.79800;-0.44400;5.72700;,
 12.77100;-1.57800;-6.41000;,
 4.57700;-1.35800;-5.77100;,
 20.97300;-1.76500;-6.64200;,
 29.17500;-1.95200;-6.87400;,
 37.39400;-2.06800;-5.60100;,
 21.21000;-0.78600;5.67100;,
 20.93500;-4.66600;3.88200;,
 29.07300;-5.33300;3.15900;,
 29.41200;-0.97400;5.44000;,
 4.79800;-0.44400;5.72700;,
 4.48400;-4.65500;3.80700;,
 12.73200;-4.44300;4.11200;,
 13.00800;-0.59900;5.90300;,
 29.41200;-0.97400;5.44000;,
 29.07300;-5.33300;3.15900;,
 37.29000;-4.55000;2.15600;,
 37.59700;-1.23200;3.46400;,
 20.97300;-1.76500;-6.64200;,
 20.77300;-5.33500;-4.52900;,
 12.56900;-5.11100;-4.29900;,
 12.77100;-1.57800;-6.41000;,
 29.17500;-1.95200;-6.87400;,
 28.93100;-5.92100;-4.23000;,
 20.77300;-5.33500;-4.52900;,
 20.97300;-1.76500;-6.64200;,
 12.77100;-1.57800;-6.41000;,
 12.56900;-5.11100;-4.29900;,
 4.34300;-5.23600;-3.49900;,
 4.57700;-1.35800;-5.77100;,
 34.22100;-4.69000;-4.14100;,
 34.22100;-1.79100;-5.23500;,
 40.86100;-1.79100;-4.14100;,
 39.13900;-3.93800;-3.28900;,
 34.22100;1.10700;-4.14100;,
 39.13900;0.35600;-3.28900;,
 34.22100;2.07400;-0.85700;,
 40.86100;1.10700;-0.85700;,
 34.22100;1.10700;2.42700;,
 39.13900;0.35600;1.57500;,
 34.22100;-1.79100;3.52100;,
 40.86100;-1.79100;2.42700;,
 34.22100;-4.69000;2.42700;,
 39.13900;-3.93800;1.57500;,
 34.22100;-5.65600;-0.85700;,
 40.86100;-4.69000;-0.85700;,
 34.22100;-4.69000;-4.14100;,
 39.13900;-3.93800;-3.28900;,
 43.07400;-1.79100;-0.85700;,
 40.86100;-4.69000;-0.85700;,
 40.86100;-1.79100;2.42700;,
 39.13900;-3.93800;1.57500;,
 40.86100;1.10700;-0.85700;,
 39.13900;0.35600;1.57500;,
 7.02700;2.74500;-3.65800;,
 7.02700;-0.77900;-4.87200;,
 2.29900;-0.77900;-3.65800;,
 3.52500;1.83200;-2.71300;,
 7.02700;-4.30400;-3.65800;,
 3.52500;-3.39000;-2.71300;,
 7.02700;-5.47900;-0.01500;,
 2.29900;-4.30400;-0.01500;,
 7.02700;-4.30400;3.62800;,
 3.52500;-3.39000;2.68400;,
 7.02700;-0.77900;4.84200;,
 2.29900;-0.77900;3.62800;,
 7.02700;2.74500;3.62800;,
 3.52500;1.83200;2.68400;,
 7.02700;3.92000;-0.01500;,
 2.29900;2.74500;-0.01500;,
 7.02700;2.74500;-3.65800;,
 3.52500;1.83200;-2.71300;,
 0.72300;-0.77900;-0.01500;,
 2.29900;2.74500;-0.01500;,
 2.29900;-0.77900;3.62800;,
 3.52500;1.83200;2.68400;,
 2.29900;-4.30400;-0.01500;,
 3.52500;-3.39000;2.68400;;
 
 80;
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
 4;43,44,45,46;,
 4;47,48,49,50;,
 4;40,39,51,52;,
 4;53,43,46,54;,
 4;55,47,50,56;,
 4;57,41,40,58;,
 4;58,40,52,59;,
 4;44,60,61,45;,
 4;62,63,42,41;,
 4;64,62,41,57;,
 4;48,65,66,49;,
 4;59,52,67,68;,
 4;69,67,52,51;,
 4;70,53,54,71;,
 4;72,55,56,73;,
 4;74,75,69,51;,
 4;39,76,74,51;,
 4;77,76,39,42;,
 4;63,78,77,42;,
 4;79,80,64,57;,
 4;81,79,57,58;,
 4;82,81,58,59;,
 4;83,82,59,68;,
 4;77,44,43,76;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;83,73,56,82;,
 4;108,109,110,111;,
 4;109,112,113,110;,
 4;112,114,115,113;,
 4;114,116,117,115;,
 4;116,118,119,117;,
 4;118,120,121,119;,
 4;120,122,123,121;,
 4;122,124,125,123;,
 4;111,110,126,127;,
 4;127,126,128,129;,
 4;126,130,131,128;,
 4;110,113,130,126;,
 4;132,133,134,135;,
 4;133,136,137,134;,
 4;136,138,139,137;,
 4;138,140,141,139;,
 4;140,142,143,141;,
 4;142,144,145,143;,
 4;144,146,147,145;,
 4;146,148,149,147;,
 4;135,134,150,151;,
 4;151,150,152,153;,
 4;150,154,155,152;,
 4;134,137,154,150;;
 
 MeshMaterialList {
  19;
  80;
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10,
  10;;
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
  109;
  -0.577333;-0.577333;-0.577385;,
  0.577368;-0.577315;-0.577368;,
  -0.577333;0.577333;-0.577385;,
  0.577368;0.577315;-0.577368;,
  -0.577350;0.577350;0.577350;,
  0.577385;0.577333;0.577333;,
  -0.577350;-0.577350;0.577350;,
  0.577385;-0.577333;0.577333;,
  -0.707107;0.707107;-0.000028;,
  0.707121;0.000000;0.707093;,
  0.000028;-0.707107;0.707107;,
  -0.707107;0.000000;0.707107;,
  0.707121;-0.707093;-0.000028;,
  -0.707107;-0.707107;-0.000028;,
  0.000028;-0.707093;-0.707121;,
  0.707107;0.000000;-0.707107;,
  0.000028;0.707093;-0.707121;,
  -0.707093;0.000000;-0.707121;,
  0.707121;0.707093;-0.000028;,
  0.000028;0.707107;0.707107;,
  0.000027;0.000000;-1.000000;,
  0.000027;1.000000;-0.000027;,
  0.000027;0.000000;1.000000;,
  0.000027;-1.000000;-0.000027;,
  1.000000;0.000000;-0.000027;,
  -1.000000;-0.000000;-0.000027;,
  0.157002;-0.099373;-0.982586;,
  0.232866;0.034342;0.971902;,
  -0.087095;-0.046823;-0.995099;,
  -0.028984;0.052189;0.998217;,
  -0.027380;-0.084328;-0.996062;,
  0.030522;0.013527;0.999443;,
  0.294411;0.954959;-0.037101;,
  -0.161098;0.984367;-0.071200;,
  0.007917;0.997106;-0.075612;,
  -0.003122;0.036836;0.999316;,
  -0.095753;0.992714;-0.073151;,
  -0.061477;-0.061506;-0.996212;,
  0.068914;-0.096399;-0.992954;,
  0.171299;0.983557;-0.057212;,
  0.136258;0.019929;0.990473;,
  0.290558;0.742512;0.603533;,
  0.174117;0.767154;0.617380;,
  0.027407;0.782546;0.621989;,
  -0.045216;0.790083;0.611329;,
  -0.092885;0.794547;0.600056;,
  0.219606;0.693488;-0.686184;,
  -0.126581;0.713156;-0.689482;,
  -0.081275;0.707903;-0.701618;,
  -0.011947;0.700081;-0.713964;,
  0.116353;0.700010;-0.704591;,
  0.012111;-0.700223;0.713822;,
  0.001327;-0.893380;0.449301;,
  -0.044785;-0.906141;0.420598;,
  -0.026537;-0.705549;0.708164;,
  0.083666;-0.717285;0.691739;,
  0.053343;-0.913002;0.404452;,
  -0.090717;-0.932627;0.349253;,
  -0.062714;-0.730093;0.680464;,
  0.105388;-0.911005;0.398701;,
  0.151614;-0.711003;0.686650;,
  -0.021324;-0.949556;-0.312872;,
  -0.026700;-0.782911;-0.621561;,
  -0.066432;-0.786763;-0.613670;,
  -0.065904;-0.957630;-0.280361;,
  0.033196;-0.964092;-0.263485;,
  0.044443;-0.807469;-0.588233;,
  -0.101747;-0.808005;-0.580323;,
  -0.107703;-0.973572;-0.201387;,
  0.085339;-0.962311;-0.258214;,
  0.109581;-0.810084;-0.575983;,
  0.344622;-0.695489;-0.630500;,
  0.344617;0.695534;-0.630454;,
  0.344617;0.695534;0.630454;,
  0.344622;-0.695489;0.630500;,
  0.487345;0.000040;0.873210;,
  0.184947;-0.724282;0.664237;,
  0.454549;-0.890722;-0.000000;,
  0.184947;-0.724282;-0.664237;,
  0.487345;0.000040;-0.873210;,
  0.184926;0.724300;-0.664222;,
  0.454539;0.890727;0.000000;,
  0.184926;0.724300;0.664222;,
  0.194770;0.000029;-0.980849;,
  0.172444;0.985019;0.000000;,
  0.194770;0.000029;0.980849;,
  0.172448;-0.985019;-0.000000;,
  0.613948;-0.591761;-0.522386;,
  -0.493697;0.622805;-0.606941;,
  -0.493735;-0.622724;-0.606993;,
  -0.493732;-0.622707;0.607013;,
  -0.493693;0.622788;0.606961;,
  -0.636027;0.000027;0.771667;,
  -0.293217;0.683903;0.668058;,
  -0.627110;0.778930;-0.000036;,
  -0.293276;0.683922;-0.668011;,
  -0.636051;0.000027;-0.771647;,
  -0.293344;-0.683837;-0.668069;,
  -0.627186;-0.778869;-0.000036;,
  -0.293285;-0.683818;0.668115;,
  -0.295004;0.000022;-0.955496;,
  -0.286167;-0.958180;-0.000032;,
  -0.294876;0.000022;0.955535;,
  -0.286039;0.958218;-0.000032;,
  -0.881207;0.472730;-0.000034;,
  0.613948;-0.591761;0.522386;,
  0.613969;0.591838;0.522274;,
  0.613969;0.591838;-0.522274;,
  -0.881231;-0.472687;-0.000034;;
  80;
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
  4;12,24,9,7;,
  4;24,18,5,9;,
  4;15,3,18,24;,
  4;6,11,25,13;,
  4;13,25,17,0;,
  4;25,8,2,17;,
  4;11,4,8,25;,
  4;43,34,36,44;,
  4;51,54,53,52;,
  4;61,64,63,62;,
  4;34,43,42,39;,
  4;55,51,52,56;,
  4;65,61,62,66;,
  4;48,36,34,49;,
  4;49,34,39,50;,
  4;54,58,57,53;,
  4;33,45,44,36;,
  4;47,33,36,48;,
  4;64,68,67,63;,
  4;50,39,32,46;,
  4;41,32,39,42;,
  4;60,55,56,59;,
  4;69,65,66,70;,
  4;40,27,41,42;,
  4;43,31,40,42;,
  4;35,31,43,44;,
  4;45,29,35,44;,
  4;37,28,47,48;,
  4;30,37,48,49;,
  4;38,30,49,50;,
  4;26,38,50,46;,
  4;35,54,51,31;,
  4;31,51,55,40;,
  4;29,58,54,35;,
  4;40,55,60,27;,
  4;30,62,63,37;,
  4;38,66,62,30;,
  4;37,63,67,28;,
  4;26,70,66,38;,
  4;78,83,79,71;,
  4;83,80,72,79;,
  4;80,84,81,72;,
  4;84,82,73,81;,
  4;82,85,75,73;,
  4;85,76,74,75;,
  4;76,86,77,74;,
  4;86,78,71,77;,
  4;71,79,87,77;,
  4;77,105,75,74;,
  4;106,81,73,75;,
  4;79,72,81,107;,
  4;95,100,96,88;,
  4;100,97,89,96;,
  4;97,101,98,89;,
  4;101,99,90,98;,
  4;99,102,92,90;,
  4;102,93,91,92;,
  4;93,103,94,91;,
  4;103,95,88,94;,
  4;88,96,104,94;,
  4;94,104,92,91;,
  4;108,98,90,92;,
  4;96,89,98,108;;
 }
 MeshTextureCoords {
  156;
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
  0.562500;0.125000;,
  0.500000;0.125000;,
  0.500000;0.187500;,
  0.562500;0.187500;,
  0.625000;0.125000;,
  0.625000;0.187500;,
  0.875000;0.187500;,
  0.875000;0.125000;,
  0.125000;0.125000;,
  0.125000;0.187500;,
  0.375000;0.187500;,
  0.375000;0.125000;,
  0.562500;0.062500;,
  0.500000;0.062500;,
  0.625000;0.062500;,
  0.875000;0.062500;,
  0.125000;0.062500;,
  0.375000;0.062500;,
  0.437500;0.187500;,
  0.437500;0.125000;,
  0.437500;0.062500;,
  0.625000;0.250000;,
  0.875000;0.250000;,
  0.500000;0.250000;,
  0.562500;0.250000;,
  0.437500;0.250000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.625000;0.062500;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.187500;,
  0.625000;0.250000;,
  0.375000;0.187500;,
  0.375000;0.250000;,
  0.375000;0.125000;,
  0.375000;0.062500;,
  0.375000;0.000000;,
  0.125000;0.187500;,
  0.125000;0.187500;,
  0.125000;0.125000;,
  0.125000;0.125000;,
  0.375000;0.062500;,
  0.375000;0.062500;,
  0.375000;0.125000;,
  0.375000;0.125000;,
  0.875000;0.250000;,
  0.875000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.187500;,
  0.625000;0.187500;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.625000;0.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.875000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.250000;;
 }
}
