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
 167;
 -1.83520;0.23780;-0.05780;,
 -1.84360;-0.21820;0.10900;,
 -1.55200;-0.21820;-0.41480;,
 -1.61700;0.39740;-0.44480;,
 -1.39020;-0.21820;-0.99860;,
 -1.49940;0.23780;-0.87820;,
 -1.61700;-0.83360;-0.44480;,
 -1.49940;-0.67400;-0.87820;,
 -1.83520;-0.67400;-0.05780;,
 -2.03820;-0.83360;0.01940;,
 -1.81140;-1.03880;-0.53440;,
 -1.58460;-0.83360;-1.08820;,
 -2.00600;-0.83360;-0.62400;,
 -1.78760;-0.67400;-1.01100;,
 -2.12340;-0.67400;-0.19060;,
 -2.23260;-0.21820;-0.07020;,
 -2.07080;-0.21820;-0.65380;,
 -1.77920;-0.21820;-1.17780;,
 -2.00600;0.39740;-0.62400;,
 -1.78760;0.23780;-1.01100;,
 -2.12340;0.23780;-0.19060;,
 -2.03820;0.39740;0.01940;,
 -1.81140;0.60260;-0.53440;,
 -1.58460;0.39740;-1.08820;,
 -1.61700;0.39740;-0.44480;,
 -1.49940;0.23780;-0.87820;,
 -1.83520;0.23780;-0.05780;,
 -1.50920;-0.21820;-1.27280;,
 -1.58460;0.39740;-1.08820;,
 -1.77920;-0.21820;-1.17780;,
 -1.78760;0.23780;-1.01100;,
 -1.58460;-0.83360;-1.08820;,
 -1.78760;-0.67400;-1.01100;,
 -2.12340;0.23780;-0.19060;,
 -2.23260;-0.21820;-0.07020;,
 -2.11380;-0.21820;0.20400;,
 -2.03820;0.39740;0.01940;,
 -2.03820;-0.83360;0.01940;,
 -2.12340;-0.67400;-0.19060;,
 -0.72720;0.56600;-0.23700;,
 -0.52740;-0.16800;-0.31260;,
 -1.26920;-0.16800;-0.44960;,
 -1.27640;0.82280;-0.34240;,
 -2.02560;-0.16800;-0.37220;,
 -1.83700;0.56600;-0.28100;,
 -1.27640;-1.15860;-0.34240;,
 -1.83700;-0.90180;-0.28100;,
 -0.72720;-0.90180;-0.23700;,
 -0.54920;-1.15860;0.00900;,
 -1.29840;-1.48880;-0.02080;,
 -2.04760;-1.15860;-0.05040;,
 -1.32040;-1.15860;0.30100;,
 -1.86960;-0.90180;0.19560;,
 -0.75980;-0.90180;0.23960;,
 -0.57120;-0.16800;0.33080;,
 -1.32760;-0.16800;0.40820;,
 -2.06940;-0.16800;0.27120;,
 -1.32040;0.82280;0.30100;,
 -1.86960;0.56600;0.19560;,
 -0.75980;0.56600;0.23960;,
 -0.54920;0.82280;0.00900;,
 -1.29840;1.15300;-0.02080;,
 -2.04760;0.82280;-0.05040;,
 -1.27640;0.82280;-0.34240;,
 -1.83700;0.56600;-0.28100;,
 -0.72720;0.56600;-0.23700;,
 -2.29720;-0.16800;-0.06040;,
 -2.04760;0.82280;-0.05040;,
 -2.06940;-0.16800;0.27120;,
 -1.86960;0.56600;0.19560;,
 -2.04760;-1.15860;-0.05040;,
 -1.86960;-0.90180;0.19560;,
 -0.75980;0.56600;0.23960;,
 -0.57120;-0.16800;0.33080;,
 -0.29960;-0.16800;0.01900;,
 -0.54920;0.82280;0.00900;,
 -0.54920;-1.15860;0.00900;,
 -0.75980;-0.90180;0.23960;,
 -0.86480;-1.27120;-0.33020;,
 -0.86480;4.67700;-0.33020;,
 -1.58820;4.67700;-0.33020;,
 -1.58820;-1.27120;-0.33020;,
 -1.18000;20.78460;-0.66180;,
 -1.18000;20.78460;-0.72220;,
 -1.27300;20.78460;-0.72220;,
 -1.27300;20.78460;-0.66180;,
 -0.86480;4.67700;-1.05380;,
 -0.86480;-1.27120;-1.05380;,
 -1.58820;-1.27120;-1.05380;,
 -1.58820;4.67700;-1.05380;,
 -0.92880;-2.19420;-1.05380;,
 -0.92880;-2.19420;-0.33020;,
 -1.52420;-2.19420;-0.33020;,
 -1.52420;-2.19420;-1.05380;,
 -1.58820;4.67700;-1.05380;,
 -1.58820;-1.27120;-1.05380;,
 -0.86480;-1.27120;-1.05380;,
 -0.86480;4.67700;-1.05380;,
 -1.92160;-1.59060;-1.05380;,
 -1.92160;-1.65300;-1.05380;,
 -1.92160;-1.65300;-0.33020;,
 -1.92160;-1.59060;-0.33020;,
 -1.58820;-1.27120;-0.33020;,
 -0.86480;-1.27120;-0.33020;,
 -0.53140;-1.59060;-0.33020;,
 -0.53140;-1.65300;-0.33020;,
 -0.53140;-1.65300;-1.05380;,
 -0.53140;-1.59060;-1.05380;,
 0.41240;4.83960;-0.33020;,
 -2.86540;4.83960;-0.33020;,
 -3.91540;4.77880;-0.48680;,
 -3.91540;4.84460;-0.48680;,
 -3.91540;4.84460;-0.89720;,
 -3.91540;4.77880;-0.89720;,
 -2.86540;4.83960;-1.05380;,
 0.41240;4.83960;-1.05380;,
 1.46240;4.77880;-0.89720;,
 1.46240;4.84460;-0.89720;,
 1.46240;4.84460;-0.48680;,
 1.46240;4.77880;-0.48680;,
 -0.34420;4.83780;-0.58680;,
 -2.10880;4.83780;-0.58680;,
 -2.10880;4.83780;-0.79720;,
 -0.34420;4.83780;-0.79720;,
 -0.64560;15.72100;-0.61540;,
 -1.80740;15.72100;-0.61540;,
 -1.80740;15.72100;-0.76840;,
 -0.64560;15.72100;-0.76840;,
 -0.06440;-0.49280;0.39940;,
 0.03340;-0.14760;0.52020;,
 -0.34360;-0.14760;0.67540;,
 -0.34360;-0.61360;0.52020;,
 -0.72040;-0.14760;0.52020;,
 -0.62260;-0.49280;0.39940;,
 -0.34360;0.31820;0.52020;,
 -0.62260;0.19740;0.39940;,
 -0.06440;0.19740;0.39940;,
 0.03340;0.31820;0.05420;,
 -0.34360;0.47360;0.05420;,
 -0.72040;0.31820;0.05420;,
 -0.34360;0.31820;-0.41160;,
 -0.62260;0.19740;-0.29080;,
 -0.06440;0.19740;-0.29080;,
 0.03340;-0.14760;-0.41160;,
 -0.34360;-0.14760;-0.56680;,
 -0.72040;-0.14760;-0.41160;,
 -0.34360;-0.61360;-0.41160;,
 -0.62260;-0.49280;-0.29080;,
 -0.06440;-0.49280;-0.29080;,
 0.03340;-0.61360;0.05420;,
 -0.34360;-0.76880;0.05420;,
 -0.72040;-0.61360;0.05420;,
 -0.34360;-0.61360;0.52020;,
 -0.62260;-0.49280;0.39940;,
 -0.06440;-0.49280;0.39940;,
 -0.84600;-0.14760;0.05420;,
 -0.72040;-0.61360;0.05420;,
 -0.72040;-0.14760;-0.41160;,
 -0.62260;-0.49280;-0.29080;,
 -0.72040;0.31820;0.05420;,
 -0.62260;0.19740;-0.29080;,
 -0.06440;-0.49280;-0.29080;,
 0.03340;-0.14760;-0.41160;,
 0.15900;-0.14760;0.05420;,
 0.03340;-0.61360;0.05420;,
 0.03340;0.31820;0.05420;,
 -0.06440;0.19740;-0.29080;;
 
 114;
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
 4;82,83,84,85;,
 4;86,87,88,89;,
 4;90,91,92,93;,
 4;81,80,94,95;,
 4;96,97,79,78;,
 4;87,90,93,88;,
 4;98,99,100,101;,
 4;102,92,91,103;,
 4;104,105,106,107;,
 4;88,98,101,102;,
 4;102,101,100,92;,
 4;92,100,99,93;,
 4;93,99,98,88;,
 4;103,104,107,87;,
 4;87,107,106,90;,
 4;90,106,105,91;,
 4;91,105,104,103;,
 4;79,108,109,80;,
 4;110,111,112,113;,
 4;89,114,115,86;,
 4;116,117,118,119;,
 4;80,110,113,89;,
 4;89,113,112,114;,
 4;114,112,111,109;,
 4;109,111,110,80;,
 4;86,116,119,79;,
 4;79,119,118,108;,
 4;108,118,117,115;,
 4;115,117,116,86;,
 4;108,120,121,109;,
 4;109,121,122,114;,
 4;114,122,123,115;,
 4;115,123,120,108;,
 4;120,124,125,121;,
 4;121,125,126,122;,
 4;122,126,127,123;,
 4;123,127,124,120;,
 4;124,82,85,125;,
 4;125,85,84,126;,
 4;126,84,83,127;,
 4;127,83,82,124;,
 4;128,129,130,131;,
 4;131,130,132,133;,
 4;130,134,135,132;,
 4;129,136,134,130;,
 4;136,137,138,134;,
 4;134,138,139,135;,
 4;138,140,141,139;,
 4;137,142,140,138;,
 4;142,143,144,140;,
 4;140,144,145,141;,
 4;144,146,147,145;,
 4;143,148,146,144;,
 4;148,149,150,146;,
 4;146,150,151,147;,
 4;150,152,153,151;,
 4;149,154,152,150;,
 4;133,132,155,156;,
 4;156,155,157,158;,
 4;155,159,160,157;,
 4;132,135,159,155;,
 4;161,162,163,164;,
 4;164,163,129,128;,
 4;163,165,136,129;,
 4;162,166,165,163;;
 
 MeshMaterialList {
  19;
  114;
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  7,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8;;
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
  141;
  0.642415;0.367922;0.672262;,
  0.933553;0.358209;-0.012836;,
  0.642407;-0.367968;0.672244;,
  0.933536;-0.358254;-0.012830;,
  -0.933536;-0.358254;0.012821;,
  -0.642407;-0.367936;-0.672262;,
  -0.933553;0.358209;0.012827;,
  -0.642415;0.367889;-0.672280;,
  0.500494;-0.469593;0.727316;,
  -0.672090;-0.000038;-0.740469;,
  -0.842118;0.413211;-0.346545;,
  -0.999323;-0.000037;0.036795;,
  -0.500467;0.469615;-0.727319;,
  -0.877329;0.457555;0.144698;,
  0.842096;0.413229;0.346576;,
  0.999317;-0.000037;-0.036945;,
  0.842086;-0.413254;0.346572;,
  0.672037;-0.000038;0.740518;,
  0.877350;-0.457498;-0.144750;,
  -0.842108;-0.413236;-0.346541;,
  0.925131;-0.000027;0.379648;,
  0.693806;-0.660648;0.286666;,
  -0.925145;-0.000027;-0.379614;,
  -0.693693;0.660803;-0.286583;,
  0.946659;-0.000045;-0.322238;,
  -0.946786;-0.000045;0.321864;,
  0.464890;0.330645;-0.821311;,
  -0.388731;0.332700;-0.859185;,
  0.464882;-0.330671;-0.821305;,
  -0.388724;-0.332725;-0.859178;,
  0.388716;-0.332790;0.859157;,
  -0.464875;-0.330719;0.821289;,
  0.388723;0.332764;0.859164;,
  -0.464883;0.330693;0.821295;,
  0.575150;-0.419417;-0.702348;,
  -0.517080;-0.000022;0.855937;,
  -0.038161;0.385834;0.921778;,
  0.433349;-0.000021;0.901226;,
  -0.575151;0.419463;0.702319;,
  0.504960;0.423490;0.752112;,
  0.038158;0.385751;-0.921813;,
  -0.433349;-0.000021;-0.901226;,
  0.038158;-0.385766;-0.921807;,
  0.517080;-0.000022;-0.855937;,
  -0.504961;-0.423419;-0.752150;,
  -0.038161;-0.385849;0.921772;,
  0.040503;-0.000015;-0.999179;,
  0.033201;-0.624048;-0.780680;,
  -0.040503;-0.000016;0.999179;,
  -0.033205;0.624189;0.780567;,
  -0.697595;-0.000025;-0.716492;,
  0.697595;-0.000025;0.716492;,
  0.000000;0.000000;1.000000;,
  0.040711;-0.112072;0.992866;,
  -0.040711;-0.112072;0.992866;,
  0.040711;-0.112072;-0.992866;,
  -0.040711;-0.112072;-0.992866;,
  0.000000;0.000000;-1.000000;,
  0.451737;-0.892151;-0.000000;,
  -0.451737;-0.892151;0.000000;,
  -0.919724;0.392566;0.000000;,
  -0.950273;-0.311420;0.000000;,
  0.919724;0.392566;0.000000;,
  0.950273;-0.311420;-0.000000;,
  0.061179;-0.168418;0.983815;,
  -0.061179;-0.168418;0.983815;,
  -0.061179;-0.168418;-0.983815;,
  0.061179;-0.168418;-0.983815;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  -0.001190;0.999993;-0.003507;,
  0.001190;0.999993;-0.003507;,
  0.001190;0.999993;0.003507;,
  -0.001190;0.999993;0.003507;,
  0.000000;0.005896;0.999983;,
  -0.997795;0.066369;0.000000;,
  0.000000;0.005885;-0.999983;,
  0.000000;1.000000;0.000000;,
  0.640705;-0.542908;0.542908;,
  -0.640826;-0.542836;0.542836;,
  0.640712;0.542902;0.542904;,
  -0.640833;0.542830;0.542833;,
  0.640672;0.542863;-0.542991;,
  -0.640793;0.542791;-0.542919;,
  0.640664;-0.542869;-0.542994;,
  -0.640786;-0.542797;-0.542923;,
  0.758776;0.651351;-0.000082;,
  -0.758754;0.000082;-0.651377;,
  -0.000128;-0.707044;-0.707169;,
  0.758674;0.000082;-0.651471;,
  -0.758804;-0.651319;-0.000082;,
  0.758723;-0.651413;-0.000082;,
  -0.000128;-0.707107;0.707107;,
  -0.758804;0.000082;0.651319;,
  -0.000128;0.707065;0.707148;,
  0.758723;0.000082;0.651413;,
  -0.758857;0.651258;-0.000082;,
  -0.000128;0.707003;-0.707211;,
  -0.000126;0.000089;1.000000;,
  -0.000127;1.000000;-0.000089;,
  -0.000126;0.000089;-1.000000;,
  -0.000126;-1.000000;-0.000089;,
  -1.000000;0.000075;-0.000075;,
  1.000000;0.000075;-0.000075;,
  -0.693693;-0.660803;-0.286583;,
  -0.500466;-0.469657;-0.727294;,
  -0.877310;-0.457595;0.144683;,
  0.693805;0.660648;0.286666;,
  0.877369;0.457458;-0.144765;,
  0.500495;0.469551;0.727342;,
  -0.413829;-0.000047;-0.910354;,
  0.413681;-0.000047;0.910422;,
  -0.033205;-0.624189;0.780567;,
  -0.575138;-0.419486;0.702316;,
  0.504948;-0.423513;0.752107;,
  0.033201;0.624048;-0.780680;,
  -0.504973;0.423397;-0.752155;,
  0.575163;0.419394;-0.702351;,
  -0.772084;-0.000025;0.635521;,
  0.772084;-0.000025;-0.635521;,
  -0.043702;-0.999045;0.000000;,
  -0.120377;-0.331384;-0.935785;,
  0.002380;0.999994;0.002338;,
  0.004762;0.999989;0.000000;,
  0.002380;0.999994;-0.002338;,
  -0.120377;-0.331384;0.935785;,
  0.043702;-0.999045;-0.000000;,
  0.120377;-0.331384;0.935785;,
  -0.002380;0.999994;-0.002338;,
  -0.004762;0.999989;0.000000;,
  -0.002380;0.999994;0.002338;,
  0.120377;-0.331384;-0.935785;,
  0.000000;0.002628;0.999997;,
  -0.999617;0.027683;0.000000;,
  0.000000;0.002646;-0.999996;,
  0.999617;0.027683;0.000000;,
  0.997795;0.066369;0.000000;,
  0.000000;0.009163;0.999958;,
  -0.994477;0.104955;0.000000;,
  0.000000;0.009124;-0.999958;,
  0.994477;0.104955;0.000000;;
  114;
  4;0,17,20,14;,
  4;14,20,15,1;,
  4;20,16,3,15;,
  4;17,2,16,20;,
  4;2,8,21,16;,
  4;16,21,18,3;,
  4;104,19,5,105;,
  4;106,4,19,104;,
  4;4,11,22,19;,
  4;19,22,9,5;,
  4;22,10,7,9;,
  4;11,6,10,22;,
  4;6,13,23,10;,
  4;10,23,12,7;,
  4;107,14,1,108;,
  4;109,0,14,107;,
  4;1,15,24,108;,
  4;12,110,9,7;,
  4;110,105,5,9;,
  4;15,3,18,24;,
  4;6,11,25,13;,
  4;109,111,17,0;,
  4;111,8,2,17;,
  4;11,4,106,25;,
  4;26,43,46,40;,
  4;40,46,41,27;,
  4;46,42,29,41;,
  4;43,28,42,46;,
  4;28,34,47,42;,
  4;42,47,44,29;,
  4;112,45,31,113;,
  4;114,30,45,112;,
  4;30,37,48,45;,
  4;45,48,35,31;,
  4;48,36,33,35;,
  4;37,32,36,48;,
  4;32,39,49,36;,
  4;36,49,38,33;,
  4;115,40,27,116;,
  4;117,26,40,115;,
  4;27,41,50,116;,
  4;38,118,35,33;,
  4;118,113,31,35;,
  4;41,29,44,50;,
  4;32,37,51,39;,
  4;117,119,43,26;,
  4;119,34,28,43;,
  4;37,30,114,51;,
  4;52,53,54,52;,
  4;77,77,77,77;,
  4;55,57,57,56;,
  4;58,58,59,59;,
  4;60,68,68,60;,
  4;62,69,69,62;,
  4;57,57,57,57;,
  4;60,61,61,60;,
  4;52,52,52,52;,
  4;62,63,63,62;,
  4;60,60,60,60;,
  4;52,52,52,52;,
  4;59,61,61,59;,
  4;57,57,57,57;,
  4;62,62,62,62;,
  4;57,57,57,57;,
  4;58,63,63,58;,
  4;52,52,52,52;,
  4;53,64,65,54;,
  4;68,68,68,68;,
  4;56,66,67,55;,
  4;69,69,69,69;,
  4;120,120,120,120;,
  4;56,121,121,66;,
  4;122,123,123,124;,
  4;65,125,125,54;,
  4;126,126,126,126;,
  4;53,127,127,64;,
  4;128,129,129,130;,
  4;67,131,131,55;,
  4;128,70,71,124;,
  4;124,71,72,122;,
  4;122,72,73,130;,
  4;130,73,70,128;,
  4;132,74,74,132;,
  4;133,75,75,133;,
  4;134,76,76,134;,
  4;135,136,136,135;,
  4;74,137,137,74;,
  4;75,138,138,75;,
  4;76,139,139,76;,
  4;136,140,140,136;,
  4;78,95,98,92;,
  4;92,98,93,79;,
  4;98,94,81,93;,
  4;95,80,94,98;,
  4;80,86,99,94;,
  4;94,99,96,81;,
  4;99,97,83,96;,
  4;86,82,97,99;,
  4;82,89,100,97;,
  4;97,100,87,83;,
  4;100,88,85,87;,
  4;89,84,88,100;,
  4;84,91,101,88;,
  4;88,101,90,85;,
  4;101,92,79,90;,
  4;91,78,92,101;,
  4;79,93,102,90;,
  4;90,102,87,85;,
  4;102,96,83,87;,
  4;93,81,96,102;,
  4;84,89,103,91;,
  4;91,103,95,78;,
  4;103,86,80,95;,
  4;89,82,86,103;;
 }
 MeshTextureCoords {
  167;
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
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.250000;,
  0.375000;0.500000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.625000;0.500000;,
  0.375000;0.750000;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.750000;,
  0.875000;0.250000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.250000;,
  0.625000;0.750000;,
  0.625000;0.750000;,
  0.625000;1.000000;,
  0.625000;1.000000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.375000;1.000000;,
  0.375000;1.000000;,
  0.375000;0.750000;,
  0.375000;0.750000;,
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.500000;,
  0.625000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.375000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
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
