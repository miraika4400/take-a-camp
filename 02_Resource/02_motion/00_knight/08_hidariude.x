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
 -0.23240;-0.26210;-0.22030;,
 -0.31060;-0.03870;-0.29840;,
 -0.00900;-0.03870;-0.39900;,
 -0.00900;-0.34030;-0.29840;,
 0.29250;-0.03870;-0.29840;,
 0.21440;-0.26210;-0.22030;,
 -0.00900;0.26290;-0.29840;,
 0.21440;0.18470;-0.22030;,
 -0.23240;0.18470;-0.22030;,
 -0.31060;0.26290;0.00310;,
 -0.00900;0.36340;0.00310;,
 0.29250;0.26290;0.00310;,
 -0.00900;0.26290;0.30470;,
 0.21440;0.18470;0.22650;,
 -0.23240;0.18470;0.22650;,
 -0.31060;-0.03870;0.30470;,
 -0.00900;-0.03870;0.40520;,
 0.29250;-0.03870;0.30470;,
 -0.00900;-0.34030;0.30470;,
 0.21440;-0.26210;0.22650;,
 -0.23240;-0.26210;0.22650;,
 -0.31060;-0.34030;0.00310;,
 -0.00900;-0.44080;0.00310;,
 0.29250;-0.34030;0.00310;,
 -0.00900;-0.34030;-0.29840;,
 0.21440;-0.26210;-0.22030;,
 -0.23240;-0.26210;-0.22030;,
 0.39310;-0.03870;0.00310;,
 0.29250;-0.34030;0.00310;,
 0.29250;-0.03870;0.30470;,
 0.21440;-0.26210;0.22650;,
 0.29250;0.26290;0.00310;,
 0.21440;0.18470;0.22650;,
 -0.23240;-0.26210;0.22650;,
 -0.31060;-0.03870;0.30470;,
 -0.41110;-0.03870;0.00310;,
 -0.31060;-0.34030;0.00310;,
 -0.31060;0.26290;0.00310;,
 -0.23240;0.18470;0.22650;,
 2.14320;0.43580;0.30990;,
 2.11490;0.53310;-0.07610;,
 1.29790;0.51040;-0.05130;,
 1.32620;0.41310;0.33470;,
 2.09350;-0.46660;0.38820;,
 1.27320;-0.44430;0.41120;,
 1.24820;-0.68620;-0.00090;,
 2.07010;-0.68710;-0.02480;,
 2.07010;-0.68700;-0.02350;,
 1.24820;-0.68610;0.00040;,
 1.25690;-0.51110;-0.42990;,
 2.07730;-0.53350;-0.45290;,
 2.95410;0.39630;0.28780;,
 2.94760;0.49370;-0.09880;,
 2.90730;-0.53330;0.31590;,
 2.89490;-0.66760;-0.04970;,
 2.89490;-0.66750;-0.04840;,
 2.89310;-0.59210;-0.42300;,
 1.31150;0.35250;-0.42790;,
 2.12850;0.37520;-0.45270;,
 2.93940;0.33570;-0.47470;,
 0.44840;-0.46550;0.38070;,
 0.44110;-0.53160;0.01630;,
 0.47210;0.37570;-0.02160;,
 0.47850;0.27830;0.36500;,
 0.46380;0.21770;-0.39760;,
 0.44110;-0.53150;0.01760;,
 0.43430;-0.52360;-0.34990;,
 3.75760;0.25140;-0.11650;,
 3.74640;0.15000;-0.40020;,
 3.75760;0.13480;0.18230;,
 3.72900;-0.45500;0.21560;,
 3.72190;-0.60650;-0.07640;,
 3.72190;-0.60640;-0.07510;,
 3.71540;-0.51220;-0.35600;,
 2.94120;-0.09740;0.54400;,
 3.75970;-0.12320;0.34640;,
 2.12100;-0.07860;0.56710;,
 1.30080;-0.05990;0.59030;,
 0.47980;-0.04440;0.57270;,
 1.27710;-0.15780;-0.64100;,
 0.45770;-0.13580;-0.57710;,
 2.09730;-0.17650;-0.66420;,
 2.91750;-0.19520;-0.68740;,
 3.73940;-0.20680;-0.56010;,
 2.12100;-0.07860;0.56710;,
 2.09350;-0.46660;0.38820;,
 2.90730;-0.53330;0.31590;,
 2.94120;-0.09740;0.54400;,
 0.47980;-0.04440;0.57270;,
 0.44840;-0.46550;0.38070;,
 1.27320;-0.44430;0.41120;,
 1.30080;-0.05990;0.59030;,
 2.94120;-0.09740;0.54400;,
 2.90730;-0.53330;0.31590;,
 3.72900;-0.45500;0.21560;,
 3.75970;-0.12320;0.34640;,
 2.09730;-0.17650;-0.66420;,
 2.07730;-0.53350;-0.45290;,
 1.25690;-0.51110;-0.42990;,
 1.27710;-0.15780;-0.64100;,
 2.91750;-0.19520;-0.68740;,
 2.89310;-0.59210;-0.42300;,
 2.07730;-0.53350;-0.45290;,
 2.09730;-0.17650;-0.66420;,
 1.27710;-0.15780;-0.64100;,
 1.25690;-0.51110;-0.42990;,
 0.43430;-0.52360;-0.34990;,
 0.45770;-0.13580;-0.57710;,
 3.42210;-0.46900;-0.41410;,
 3.42210;-0.17910;-0.52350;,
 4.08610;-0.17910;-0.41410;,
 3.91390;-0.39380;-0.32890;,
 3.42210;0.11070;-0.41410;,
 3.91390;0.03560;-0.32890;,
 3.42210;0.20740;-0.08570;,
 4.08610;0.11070;-0.08570;,
 3.42210;0.11070;0.24270;,
 3.91390;0.03560;0.15750;,
 3.42210;-0.17910;0.35210;,
 4.08610;-0.17910;0.24270;,
 3.42210;-0.46900;0.24270;,
 3.91390;-0.39380;0.15750;,
 3.42210;-0.56560;-0.08570;,
 4.08610;-0.46900;-0.08570;,
 3.42210;-0.46900;-0.41410;,
 3.91390;-0.39380;-0.32890;,
 4.30740;-0.17910;-0.08570;,
 4.08610;-0.46900;-0.08570;,
 4.08610;-0.17910;0.24270;,
 3.91390;-0.39380;0.15750;,
 4.08610;0.11070;-0.08570;,
 3.91390;0.03560;0.15750;,
 0.70270;0.27450;-0.36580;,
 0.70270;-0.07790;-0.48720;,
 0.22990;-0.07790;-0.36580;,
 0.35250;0.18320;-0.27130;,
 0.70270;-0.43040;-0.36580;,
 0.35250;-0.33900;-0.27130;,
 0.70270;-0.54790;-0.00150;,
 0.22990;-0.43040;-0.00150;,
 0.70270;-0.43040;0.36280;,
 0.35250;-0.33900;0.26840;,
 0.70270;-0.07790;0.48420;,
 0.22990;-0.07790;0.36280;,
 0.70270;0.27450;0.36280;,
 0.35250;0.18320;0.26840;,
 0.70270;0.39200;-0.00150;,
 0.22990;0.27450;-0.00150;,
 0.70270;0.27450;-0.36580;,
 0.35250;0.18320;-0.27130;,
 0.07230;-0.07790;-0.00150;,
 0.22990;0.27450;-0.00150;,
 0.22990;-0.07790;0.36280;,
 0.35250;0.18320;0.26840;,
 0.22990;-0.43040;-0.00150;,
 0.35250;-0.33900;0.26840;;
 
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
