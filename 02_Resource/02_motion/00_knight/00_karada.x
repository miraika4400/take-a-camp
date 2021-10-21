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
 75;
 15.31900;10.42800;-8.17900;,
 0.00000;10.43700;-12.19600;,
 0.00000;44.72300;-22.30600;,
 22.90800;44.72300;-17.14200;,
 -15.31900;10.42800;-8.17900;,
 -22.90800;44.72300;-17.14200;,
 -23.38600;50.18500;-12.44900;,
 0.00000;53.69500;-17.14200;,
 23.38600;50.18500;-12.44900;,
 0.00000;61.57200;-1.65000;,
 22.90800;53.69500;-1.65000;,
 -22.90800;53.69500;-1.65000;,
 -16.96900;47.56800;13.39200;,
 0.00000;53.69500;13.84200;,
 16.96900;47.56800;13.39200;,
 0.00000;30.06300;13.99300;,
 22.90800;30.06300;13.84200;,
 -22.90800;30.06300;13.84200;,
 -16.96900;9.28200;13.72400;,
 0.00000;8.38800;13.84200;,
 16.96900;9.28200;13.72400;,
 0.00000;8.84400;-1.65000;,
 18.75100;10.20800;-1.65000;,
 -18.75100;10.20800;-1.65000;,
 -15.31900;10.42800;-8.17900;,
 0.00000;10.43700;-12.19600;,
 15.31900;10.42800;-8.17900;,
 -18.75100;10.20800;-1.65000;,
 -25.49900;30.06300;-1.65000;,
 -16.96900;9.28200;13.72400;,
 -22.90800;30.06300;13.84200;,
 -16.96900;47.56800;13.39200;,
 -22.90800;53.69500;-1.65000;,
 16.96900;9.28200;13.72400;,
 18.75100;10.20800;-1.65000;,
 25.49900;30.06300;-1.65000;,
 22.90800;30.06300;13.84200;,
 22.90800;53.69500;-1.65000;,
 16.96900;47.56800;13.39200;,
 -14.42200;4.19800;-1.85500;,
 -3.92000;3.85100;7.51300;,
 -11.14000;14.23500;6.11800;,
 -15.69900;10.00800;-1.85500;,
 -9.09200;5.02400;-8.91300;,
 -10.68100;14.23500;-8.32500;,
 15.69900;10.00800;-1.85500;,
 14.42200;4.19800;-1.85500;,
 9.09200;5.02400;-8.91300;,
 10.68100;14.23500;-6.01400;,
 11.14000;14.23500;6.11800;,
 3.92000;3.85100;7.51300;,
 10.68100;14.23500;-6.01400;,
 9.09200;5.02400;-8.91300;,
 10.68300;21.43500;-6.96000;,
 14.32200;22.96200;-7.68600;,
 0.00000;19.90700;-10.61700;,
 0.00000;1.09700;-9.44100;,
 -9.09200;5.02400;-8.91300;,
 -10.68300;21.43500;-6.96000;,
 -14.32200;22.96200;-7.68600;,
 -10.68100;14.23500;-8.32500;,
 -15.69900;10.00800;-1.85500;,
 -18.01100;19.92100;-1.85500;,
 -11.14000;14.23500;6.11800;,
 -14.32200;22.96200;6.36500;,
 -10.68300;21.43500;7.50700;,
 -14.32200;22.96200;6.36500;,
 0.00000;19.90700;7.92700;,
 0.00000;0.91200;8.90900;,
 10.68300;21.43500;7.50700;,
 14.32200;22.96200;6.36500;,
 11.14000;14.23500;6.11800;,
 15.69900;10.00800;-1.85500;,
 18.01100;19.92100;-1.85500;,
 14.32200;22.96200;6.36500;;
 
 46;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;2,5,6,7;,
 4;3,2,7,8;,
 4;8,7,9,10;,
 4;7,6,11,9;,
 4;9,11,12,13;,
 4;10,9,13,14;,
 4;14,13,15,16;,
 4;13,12,17,15;,
 4;15,17,18,19;,
 4;16,15,19,20;,
 4;20,19,21,22;,
 4;19,18,23,21;,
 4;21,23,24,25;,
 4;22,21,25,26;,
 4;4,27,28,5;,
 4;27,29,30,28;,
 4;28,30,31,32;,
 4;5,28,32,6;,
 4;33,34,35,36;,
 4;34,0,3,35;,
 4;35,3,8,37;,
 4;36,35,37,38;,
 4;39,40,41,42;,
 4;43,39,42,44;,
 4;45,46,47,48;,
 4;49,50,46,45;,
 4;51,52,53,54;,
 4;55,53,52,56;,
 4;56,57,58,55;,
 4;59,58,57,60;,
 4;60,61,62,59;,
 4;61,63,64,62;,
 4;40,65,66,41;,
 4;67,65,40,68;,
 4;50,69,67,68;,
 4;70,69,50,49;,
 4;71,72,73,74;,
 4;72,51,54,73;,
 3;46,50,47;,
 3;47,50,56;,
 3;50,68,56;,
 3;68,40,56;,
 3;56,40,57;,
 3;40,39,57;;
 
 MeshMaterialList {
  19;
  46;
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
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
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
  83;
  0.585827;-0.313722;-0.747252;,
  -0.585827;-0.313722;-0.747252;,
  0.242175;0.756642;-0.607326;,
  -0.242175;0.756642;-0.607326;,
  0.694773;0.592929;0.407094;,
  -0.694773;0.592929;0.407094;,
  0.006956;-0.007264;0.999949;,
  -0.006956;-0.007264;0.999949;,
  0.301170;0.952621;0.042547;,
  -0.012331;0.004949;0.999912;,
  0.000000;-0.007264;0.999974;,
  0.012331;0.004949;0.999912;,
  -0.059005;-0.995395;-0.075545;,
  0.059005;-0.995395;-0.075545;,
  0.000000;-0.290040;-0.957015;,
  -0.715012;0.015888;-0.698932;,
  0.000000;0.779856;-0.625959;,
  0.715012;0.015888;-0.698932;,
  -0.301170;0.952621;0.042547;,
  0.000000;0.885132;0.465339;,
  0.000000;0.156351;-0.987702;,
  0.000000;0.999004;0.044619;,
  0.000000;0.004950;0.999988;,
  0.000000;-0.997132;-0.075677;,
  -0.996304;-0.081917;-0.025847;,
  0.996304;-0.081917;-0.025847;,
  0.017703;0.017161;0.999696;,
  0.000000;0.017164;0.999853;,
  -0.017703;0.017161;0.999696;,
  0.062427;-0.997228;-0.040493;,
  0.000000;-0.999177;-0.040572;,
  -0.062427;-0.997228;-0.040493;,
  -0.055510;-0.992324;-0.110503;,
  0.000000;-0.993857;-0.110674;,
  0.055510;-0.992324;-0.110503;,
  -0.937157;-0.307846;-0.164217;,
  -0.946852;-0.296173;0.125513;,
  -0.976436;-0.042975;0.211486;,
  -0.983286;0.144326;0.110987;,
  -0.995473;0.070072;-0.064213;,
  0.946852;-0.296173;0.125513;,
  0.937157;-0.307846;-0.164217;,
  0.976436;-0.042975;0.211486;,
  0.995473;0.070072;-0.064213;,
  0.983286;0.144326;0.110987;,
  0.631200;-0.139622;-0.762949;,
  -0.752557;-0.174224;-0.635063;,
  0.660801;-0.230425;0.714315;,
  -0.660801;-0.230425;0.714315;,
  0.000000;0.017215;0.999852;,
  -0.773165;-0.258205;0.579264;,
  0.689118;-0.151897;-0.708551;,
  0.000000;0.010402;-0.999946;,
  -0.210848;0.018896;-0.977336;,
  -0.727999;-0.264414;0.632537;,
  -0.445162;-0.139818;0.884467;,
  0.498980;-0.046351;-0.865373;,
  0.740793;-0.031834;-0.670978;,
  0.445162;-0.139818;0.884467;,
  0.568380;-0.192193;-0.800004;,
  0.357855;-0.052022;-0.932327;,
  0.121807;0.094457;-0.988049;,
  0.430395;0.168246;-0.886822;,
  -0.735379;-0.217831;-0.641691;,
  -0.622331;-0.211478;0.753645;,
  -0.275827;-0.068585;0.958757;,
  0.275827;-0.068585;0.958757;,
  0.622331;-0.211478;0.753645;,
  0.814530;-0.250725;0.523142;,
  -0.768048;-0.130227;-0.627011;,
  0.727999;-0.264414;0.632537;,
  0.773165;-0.258205;0.579264;,
  -0.814530;-0.250725;0.523142;,
  0.624695;-0.269151;-0.733017;,
  -0.042442;-0.995523;-0.084455;,
  0.329837;-0.943962;-0.011937;,
  0.180207;-0.983536;-0.013494;,
  0.220995;-0.974453;0.040034;,
  0.598006;-0.801451;-0.008080;,
  -0.598006;-0.801451;-0.008080;,
  -0.329837;-0.943962;-0.011937;,
  -0.180207;-0.983536;-0.013494;,
  0.042442;-0.995523;-0.084455;;
  46;
  4;0,14,20,17;,
  4;14,1,15,20;,
  4;20,15,3,16;,
  4;17,20,16,2;,
  4;2,16,21,8;,
  4;16,3,18,21;,
  4;21,18,5,19;,
  4;8,21,19,4;,
  4;26,27,22,11;,
  4;27,28,9,22;,
  4;22,9,7,10;,
  4;11,22,10,6;,
  4;29,30,23,13;,
  4;30,31,12,23;,
  4;23,12,32,33;,
  4;13,23,33,34;,
  4;1,35,24,15;,
  4;35,36,37,24;,
  4;24,37,5,38;,
  4;15,24,38,39;,
  4;40,41,25,42;,
  4;41,0,17,25;,
  4;25,17,43,44;,
  4;42,25,44,4;,
  4;54,55,48,50;,
  4;53,69,46,46;,
  4;51,57,56,45;,
  4;47,58,70,71;,
  4;45,56,60,59;,
  4;52,60,56,52;,
  4;52,53,61,52;,
  4;62,61,53,62;,
  4;46,46,63,63;,
  4;50,48,64,72;,
  4;55,65,64,48;,
  4;49,65,55,49;,
  4;58,66,49,49;,
  4;67,66,58,47;,
  4;47,71,68,67;,
  4;51,45,59,73;,
  3;74,75,76;,
  3;76,75,77;,
  3;75,78,77;,
  3;79,80,79;,
  3;77,80,81;,
  3;80,82,81;;
 }
 MeshTextureCoords {
  75;
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.375000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.625000;,
  0.375000;0.625000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.125000;0.125000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.562500;0.875000;,
  0.562500;0.750000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.562500;1.000000;,
  0.625000;1.000000;,
  0.375000;0.875000;,
  0.437500;0.875000;,
  0.437500;1.000000;,
  0.375000;1.000000;,
  0.375000;0.750000;,
  0.437500;0.750000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.437500;0.062500;,
  0.375000;0.062500;,
  0.500000;0.062500;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.562500;0.062500;,
  0.625000;0.062500;,
  0.625000;0.000000;,
  0.750000;0.000000;,
  0.750000;0.062500;,
  0.875000;0.000000;,
  0.875000;0.062500;,
  0.562500;0.687500;,
  0.625000;0.687500;,
  0.500000;0.687500;,
  0.500000;0.750000;,
  0.437500;0.687500;,
  0.375000;0.687500;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.062500;,
  0.125000;0.062500;;
 }
}
