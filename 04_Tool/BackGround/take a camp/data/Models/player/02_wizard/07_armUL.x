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
 251;
 1.37322;-0.40902;0.08980;,
 1.49682;-0.34272;0.13080;,
 1.45792;-0.34272;0.20890;,
 1.35272;-0.40902;0.13080;,
 1.39722;-0.34272;0.27090;,
 1.32082;-0.40902;0.16340;,
 1.32082;-0.34272;0.31070;,
 1.28062;-0.40902;0.18430;,
 1.23612;-0.34272;0.32440;,
 1.23612;-0.40902;0.19150;,
 1.23612;-0.40902;-0.10310;,
 1.23612;-0.34272;-0.23600;,
 1.32082;-0.34272;-0.22230;,
 1.28062;-0.40902;-0.09590;,
 1.39722;-0.34272;-0.18250;,
 1.32082;-0.40902;-0.07490;,
 1.45792;-0.34272;-0.12050;,
 1.35272;-0.40902;-0.04240;,
 1.49682;-0.34272;-0.04240;,
 1.37322;-0.40902;-0.00130;,
 1.51022;-0.34272;0.04420;,
 1.38022;-0.40902;0.04420;,
 1.49682;-0.34272;0.13080;,
 1.37322;-0.40902;0.08980;,
 1.59492;-0.23962;0.16340;,
 1.54132;-0.23962;0.27090;,
 1.45792;-0.23962;0.35620;,
 1.35272;-0.23962;0.41100;,
 1.23612;-0.23962;0.42990;,
 1.23612;-0.23962;-0.34140;,
 1.35272;-0.23962;-0.32260;,
 1.45792;-0.23962;-0.26780;,
 1.54132;-0.23962;-0.18250;,
 1.59492;-0.23962;-0.07490;,
 1.61342;-0.23962;0.04420;,
 1.59492;-0.23962;0.16340;,
 1.65792;-0.10962;0.18430;,
 1.59492;-0.10962;0.31070;,
 1.49682;-0.10962;0.41100;,
 1.37322;-0.10962;0.47540;,
 1.23612;-0.10962;0.49760;,
 1.23612;-0.10962;-0.40920;,
 1.37322;-0.10962;-0.38700;,
 1.49682;-0.10962;-0.32260;,
 1.59492;-0.10962;-0.22230;,
 1.65792;-0.10962;-0.09590;,
 1.67962;-0.10962;0.04420;,
 1.65792;-0.10962;0.18430;,
 1.67962;0.03448;0.19150;,
 1.61342;0.03448;0.32440;,
 1.51022;0.03448;0.42990;,
 1.38022;0.03448;0.49760;,
 1.23612;0.03448;0.52090;,
 1.23612;0.03448;-0.43250;,
 1.38022;0.03448;-0.40920;,
 1.51022;0.03448;-0.34140;,
 1.61342;0.03448;-0.23600;,
 1.67962;0.03448;-0.10310;,
 1.70242;0.03448;0.04420;,
 1.67962;0.03448;0.19150;,
 1.65792;0.17858;0.18430;,
 1.59492;0.17858;0.31070;,
 1.49682;0.17858;0.41100;,
 1.37322;0.17858;0.47540;,
 1.23612;0.17858;0.49760;,
 1.23612;0.17858;-0.40920;,
 1.37322;0.17858;-0.38700;,
 1.49682;0.17858;-0.32260;,
 1.59492;0.17858;-0.22230;,
 1.65792;0.17858;-0.09590;,
 1.67962;0.17858;0.04420;,
 1.65792;0.17858;0.18430;,
 1.59492;0.30858;0.16340;,
 1.54132;0.30858;0.27090;,
 1.45792;0.30858;0.35620;,
 1.35272;0.30858;0.41100;,
 1.23612;0.30858;0.42990;,
 1.23612;0.30858;-0.34140;,
 1.35272;0.30858;-0.32260;,
 1.45792;0.30858;-0.26780;,
 1.54132;0.30858;-0.18250;,
 1.59492;0.30858;-0.07490;,
 1.61342;0.30858;0.04420;,
 1.59492;0.30858;0.16340;,
 1.49682;0.41168;0.13080;,
 1.45792;0.41168;0.20890;,
 1.39722;0.41168;0.27090;,
 1.32082;0.41168;0.31070;,
 1.23612;0.41168;0.32440;,
 1.23612;0.41168;-0.23600;,
 1.32082;0.41168;-0.22230;,
 1.39722;0.41168;-0.18250;,
 1.45792;0.41168;-0.12050;,
 1.49682;0.41168;-0.04240;,
 1.51022;0.41168;0.04420;,
 1.49682;0.41168;0.13080;,
 1.37322;0.47798;0.08980;,
 1.35272;0.47798;0.13080;,
 1.32082;0.47798;0.16340;,
 1.28062;0.47798;0.18430;,
 1.23612;0.47798;0.19150;,
 1.23612;0.47798;-0.10310;,
 1.28062;0.47798;-0.09590;,
 1.32082;0.47798;-0.07490;,
 1.35272;0.47798;-0.04240;,
 1.37322;0.47798;-0.00130;,
 1.38022;0.47798;0.04420;,
 1.37322;0.47798;0.08980;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;-0.43182;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23612;0.50078;0.04420;,
 1.23722;0.47758;0.19150;,
 0.13872;0.38648;0.15880;,
 0.13872;0.33488;0.26220;,
 1.23722;0.41128;0.32440;,
 0.13872;0.25458;0.34430;,
 1.23722;0.30808;0.42990;,
 0.13872;0.15338;0.39700;,
 1.23722;0.17808;0.49770;,
 0.13872;0.04118;0.41520;,
 1.23722;0.03388;0.52100;,
 0.13872;-0.07092;0.39700;,
 1.23722;-0.11022;0.49770;,
 0.13872;-0.17212;0.34430;,
 1.23722;-0.24032;0.42990;,
 0.13872;-0.25252;0.26220;,
 1.23722;-0.34352;0.32440;,
 0.13872;-0.30402;0.15880;,
 1.23722;-0.40972;0.19150;,
 0.13872;-0.32182;0.04410;,
 1.23722;-0.43262;0.04410;,
 0.13872;-0.30402;-0.07060;,
 1.23722;-0.40972;-0.10330;,
 0.13872;-0.25252;-0.17410;,
 1.23722;-0.34352;-0.23630;,
 0.13872;-0.17212;-0.25620;,
 1.23722;-0.24032;-0.34180;,
 0.13872;-0.07092;-0.30890;,
 1.23722;-0.11022;-0.40950;,
 0.13872;0.04118;-0.32710;,
 1.23722;0.03388;-0.43280;,
 0.13872;0.15338;-0.30890;,
 1.23722;0.17808;-0.40950;,
 0.13872;0.25458;-0.25620;,
 1.23722;0.30808;-0.34180;,
 0.13872;0.33488;-0.17410;,
 1.23722;0.41128;-0.23630;,
 0.13872;0.38648;-0.07060;,
 1.23722;0.47758;-0.10330;,
 0.13872;0.40428;0.04410;,
 1.23722;0.50038;0.04410;,
 0.13872;0.38648;0.15880;,
 1.23722;0.47758;0.19150;,
 1.23722;0.41128;0.32440;,
 1.23722;0.03388;0.04410;,
 1.23722;0.47758;0.19150;,
 1.23722;0.30808;0.42990;,
 1.23722;0.17808;0.49770;,
 1.23722;0.03388;0.52100;,
 1.23722;-0.11022;0.49770;,
 1.23722;-0.24032;0.42990;,
 1.23722;-0.34352;0.32440;,
 1.23722;-0.40972;0.19150;,
 1.23722;-0.43262;0.04410;,
 1.23722;-0.40972;-0.10330;,
 1.23722;-0.34352;-0.23630;,
 1.23722;-0.24032;-0.34180;,
 1.23722;-0.11022;-0.40950;,
 1.23722;0.03388;-0.43280;,
 1.23722;0.17808;-0.40950;,
 1.23722;0.30808;-0.34180;,
 1.23722;0.41128;-0.23630;,
 1.23722;0.47758;-0.10330;,
 1.23722;0.50038;0.04410;,
 0.13872;0.38648;0.15880;,
 0.13872;0.04118;0.04410;,
 0.13872;0.33488;0.26220;,
 0.13872;0.25458;0.34430;,
 0.13872;0.15338;0.39700;,
 0.13872;0.04118;0.41520;,
 0.13872;-0.07092;0.39700;,
 0.13872;-0.17212;0.34430;,
 0.13872;-0.25252;0.26220;,
 0.13872;-0.30402;0.15880;,
 0.13872;-0.32182;0.04410;,
 0.13872;-0.30402;-0.07060;,
 0.13872;-0.25252;-0.17410;,
 0.13872;-0.17212;-0.25620;,
 0.13872;-0.07092;-0.30890;,
 0.13872;0.04118;-0.32710;,
 0.13872;0.15338;-0.30890;,
 0.13872;0.25458;-0.25620;,
 0.13872;0.33488;-0.17410;,
 0.13872;0.38648;-0.07060;,
 0.13872;0.40428;0.04410;,
 -0.22318;-0.22012;-0.15100;,
 -0.30008;-0.00032;-0.22790;,
 -0.00338;-0.00032;-0.32680;,
 -0.00338;-0.29702;-0.22790;,
 0.29332;-0.00032;-0.22790;,
 0.21642;-0.22012;-0.15100;,
 -0.00338;0.29638;-0.22790;,
 0.21642;0.21938;-0.15100;,
 -0.22318;0.21938;-0.15100;,
 -0.30008;0.29638;0.06880;,
 -0.00338;0.39528;0.06880;,
 0.29332;0.29638;0.06880;,
 -0.00338;0.29638;0.36550;,
 0.21642;0.21938;0.28860;,
 -0.22318;0.21938;0.28860;,
 -0.30008;-0.00032;0.36550;,
 -0.00338;-0.00032;0.46440;,
 0.29332;-0.00032;0.36550;,
 -0.00338;-0.29702;0.36550;,
 0.21642;-0.22012;0.28860;,
 -0.22318;-0.22012;0.28860;,
 -0.30008;-0.29702;0.06880;,
 -0.00338;-0.39592;0.06880;,
 0.29332;-0.29702;0.06880;,
 -0.00338;-0.29702;-0.22790;,
 0.21642;-0.22012;-0.15100;,
 -0.22318;-0.22012;-0.15100;,
 0.39222;-0.00032;0.06880;,
 0.29332;-0.29702;0.06880;,
 0.29332;-0.00032;0.36550;,
 0.21642;-0.22012;0.28860;,
 0.29332;0.29638;0.06880;,
 0.21642;0.21938;0.28860;,
 -0.22318;-0.22012;0.28860;,
 -0.30008;-0.00032;0.36550;,
 -0.39898;-0.00032;0.06880;,
 -0.30008;-0.29702;0.06880;,
 -0.30008;0.29638;0.06880;,
 -0.22318;0.21938;0.28860;;
 
 184;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;10,11,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;17,16,18,19;,
 4;19,18,20,21;,
 4;21,20,22,23;,
 4;1,24,25,2;,
 4;2,25,26,4;,
 4;4,26,27,6;,
 4;6,27,28,8;,
 4;11,29,30,12;,
 4;12,30,31,14;,
 4;14,31,32,16;,
 4;16,32,33,18;,
 4;18,33,34,20;,
 4;20,34,35,22;,
 4;24,36,37,25;,
 4;25,37,38,26;,
 4;26,38,39,27;,
 4;27,39,40,28;,
 4;29,41,42,30;,
 4;30,42,43,31;,
 4;31,43,44,32;,
 4;32,44,45,33;,
 4;33,45,46,34;,
 4;34,46,47,35;,
 4;36,48,49,37;,
 4;37,49,50,38;,
 4;38,50,51,39;,
 4;39,51,52,40;,
 4;41,53,54,42;,
 4;42,54,55,43;,
 4;43,55,56,44;,
 4;44,56,57,45;,
 4;45,57,58,46;,
 4;46,58,59,47;,
 4;48,60,61,49;,
 4;49,61,62,50;,
 4;50,62,63,51;,
 4;51,63,64,52;,
 4;53,65,66,54;,
 4;54,66,67,55;,
 4;55,67,68,56;,
 4;56,68,69,57;,
 4;57,69,70,58;,
 4;58,70,71,59;,
 4;60,72,73,61;,
 4;61,73,74,62;,
 4;62,74,75,63;,
 4;63,75,76,64;,
 4;65,77,78,66;,
 4;66,78,79,67;,
 4;67,79,80,68;,
 4;68,80,81,69;,
 4;69,81,82,70;,
 4;70,82,83,71;,
 4;72,84,85,73;,
 4;73,85,86,74;,
 4;74,86,87,75;,
 4;75,87,88,76;,
 4;77,89,90,78;,
 4;78,90,91,79;,
 4;79,91,92,80;,
 4;80,92,93,81;,
 4;81,93,94,82;,
 4;82,94,95,83;,
 4;84,96,97,85;,
 4;85,97,98,86;,
 4;86,98,99,87;,
 4;87,99,100,88;,
 4;89,101,102,90;,
 4;90,102,103,91;,
 4;91,103,104,92;,
 4;92,104,105,93;,
 4;93,105,106,94;,
 4;94,106,107,95;,
 3;3,108,0;,
 3;5,109,3;,
 3;7,110,5;,
 3;9,111,7;,
 3;13,112,10;,
 3;15,113,13;,
 3;17,114,15;,
 3;19,115,17;,
 3;21,116,19;,
 3;23,117,21;,
 3;96,118,97;,
 3;97,119,98;,
 3;98,120,99;,
 3;99,121,100;,
 3;101,122,102;,
 3;102,123,103;,
 3;103,124,104;,
 3;104,125,105;,
 3;105,126,106;,
 3;106,127,107;,
 4;128,129,130,131;,
 4;131,130,132,133;,
 4;133,132,134,135;,
 4;135,134,136,137;,
 4;137,136,138,139;,
 4;139,138,140,141;,
 4;141,140,142,143;,
 4;143,142,144,145;,
 4;145,144,146,147;,
 4;147,146,148,149;,
 4;149,148,150,151;,
 4;151,150,152,153;,
 4;153,152,154,155;,
 4;155,154,156,157;,
 4;157,156,158,159;,
 4;159,158,160,161;,
 4;161,160,162,163;,
 4;163,162,164,165;,
 4;165,164,166,167;,
 4;167,166,168,169;,
 3;170,171,172;,
 3;173,171,170;,
 3;174,171,173;,
 3;175,171,174;,
 3;176,171,175;,
 3;177,171,176;,
 3;178,171,177;,
 3;179,171,178;,
 3;180,171,179;,
 3;181,171,180;,
 3;182,171,181;,
 3;183,171,182;,
 3;184,171,183;,
 3;185,171,184;,
 3;186,171,185;,
 3;187,171,186;,
 3;188,171,187;,
 3;189,171,188;,
 3;190,171,189;,
 3;172,171,190;,
 3;191,192,193;,
 3;193,192,194;,
 3;194,192,195;,
 3;195,192,196;,
 3;196,192,197;,
 3;197,192,198;,
 3;198,192,199;,
 3;199,192,200;,
 3;200,192,201;,
 3;201,192,202;,
 3;202,192,203;,
 3;203,192,204;,
 3;204,192,205;,
 3;205,192,206;,
 3;206,192,207;,
 3;207,192,208;,
 3;208,192,209;,
 3;209,192,210;,
 3;210,192,211;,
 3;211,192,191;,
 4;212,213,214,215;,
 4;215,214,216,217;,
 4;214,218,219,216;,
 4;213,220,218,214;,
 4;220,221,222,218;,
 4;218,222,223,219;,
 4;222,224,225,223;,
 4;221,226,224,222;,
 4;226,227,228,224;,
 4;224,228,229,225;,
 4;228,230,231,229;,
 4;227,232,230,228;,
 4;232,233,234,230;,
 4;230,234,235,231;,
 4;234,236,237,235;,
 4;233,238,236,234;,
 4;217,216,239,240;,
 4;240,239,241,242;,
 4;239,243,244,241;,
 4;216,219,243,239;,
 4;245,246,247,248;,
 4;248,247,213,212;,
 4;247,249,220,213;,
 4;246,250,249,247;;
 
 MeshMaterialList {
  5;
  184;
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
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.016000;0.000000;0.096000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.520000;0.232000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.056000;0.016000;0.000000;1.000000;;
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
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  149;
  0.293902;-0.951263;0.093384;,
  0.250105;-0.951723;0.177963;,
  0.181838;-0.952305;0.245050;,
  0.095629;-0.952771;0.288241;,
  0.048981;-0.951806;0.302766;,
  0.048981;-0.951806;-0.302766;,
  0.095796;-0.952781;-0.288153;,
  0.181877;-0.952300;-0.245042;,
  0.250025;-0.951744;-0.177967;,
  0.293917;-0.951264;-0.093326;,
  0.309012;-0.951058;-0.000029;,
  0.559290;-0.809681;0.177798;,
  0.476615;-0.811127;0.338984;,
  0.347056;-0.812958;0.467602;,
  0.182796;-0.814437;0.550706;,
  0.093382;-0.811444;0.576921;,
  0.093250;-0.811377;-0.577037;,
  0.182827;-0.814428;-0.550709;,
  0.347059;-0.812974;-0.467571;,
  0.476590;-0.811154;-0.338957;,
  0.559319;-0.809671;-0.177749;,
  0.587625;-0.809133;-0.000028;,
  0.770211;-0.588847;0.245018;,
  0.657465;-0.590858;0.467576;,
  0.479746;-0.593402;0.646311;,
  0.253126;-0.595459;0.762467;,
  0.128944;-0.591268;0.796100;,
  0.128607;-0.591308;-0.796125;,
  0.252958;-0.595492;-0.762497;,
  0.479746;-0.593402;-0.646311;,
  0.657501;-0.590870;-0.467510;,
  0.770226;-0.588848;-0.244971;,
  0.808776;-0.588116;-0.000026;,
  0.906092;-0.309695;0.288248;,
  0.774416;-0.311216;0.550839;,
  0.565991;-0.313042;0.762666;,
  0.298982;-0.314498;0.900945;,
  0.151878;-0.311380;0.938070;,
  0.151684;-0.311536;-0.938050;,
  0.298970;-0.314513;-0.900943;,
  0.566031;-0.312906;-0.762692;,
  0.774410;-0.311192;-0.550861;,
  0.906089;-0.309733;-0.288217;,
  0.951032;-0.309092;-0.000013;,
  0.952962;0.000001;0.303089;,
  0.814869;0.000002;0.579645;,
  0.595873;-0.000001;0.803079;,
  0.314881;-0.000001;0.949131;,
  0.159732;0.000000;0.987160;,
  0.159732;0.000000;-0.987160;,
  0.315028;-0.000002;-0.949082;,
  0.595898;-0.000002;-0.803060;,
  0.814799;0.000002;-0.579744;,
  0.952962;0.000002;-0.303089;,
  1.000000;-0.000001;-0.000000;,
  0.906093;0.309691;0.288248;,
  0.774416;0.311215;0.550840;,
  0.565992;0.313038;0.762666;,
  0.298982;0.314499;0.900944;,
  0.151877;0.311385;0.938069;,
  0.151685;0.311515;-0.938056;,
  0.298971;0.314501;-0.900947;,
  0.566032;0.312901;-0.762693;,
  0.774409;0.311195;-0.550861;,
  0.906087;0.309738;-0.288216;,
  0.951034;0.309086;-0.000013;,
  0.770210;0.588850;0.245016;,
  0.657461;0.590862;0.467575;,
  0.479747;0.593399;0.646313;,
  0.253126;0.595455;0.762470;,
  0.128945;0.591261;0.796105;,
  0.128611;0.591275;-0.796149;,
  0.252960;0.595475;-0.762509;,
  0.479747;0.593399;-0.646313;,
  0.657501;0.590869;-0.467510;,
  0.770224;0.588850;-0.244970;,
  0.808780;0.588112;-0.000026;,
  0.559282;0.809687;0.177794;,
  0.476610;0.811131;0.338983;,
  0.347058;0.812957;0.467603;,
  0.182797;0.814435;0.550709;,
  0.093383;0.811439;0.576928;,
  0.093252;0.811367;-0.577050;,
  0.182821;0.814434;-0.550703;,
  0.347051;0.812986;-0.467557;,
  0.476596;0.811149;-0.338959;,
  0.559325;0.809666;-0.177753;,
  0.587623;0.809135;-0.000028;,
  0.293900;0.951264;0.093383;,
  0.250106;0.951723;0.177964;,
  0.181839;0.952305;0.245051;,
  0.095628;0.952772;0.288238;,
  0.048981;0.951807;0.302762;,
  0.048981;0.951806;-0.302763;,
  0.095788;0.952787;-0.288135;,
  0.181867;0.952306;-0.245025;,
  0.250030;0.951742;-0.177969;,
  0.293922;0.951262;-0.093329;,
  0.309010;0.951059;-0.000029;,
  0.101824;-0.994802;-0.000003;,
  0.101824;0.994802;-0.000003;,
  -0.087706;0.949194;0.302224;,
  -0.089135;0.811466;0.577562;,
  -0.091236;0.593467;0.799670;,
  -0.093636;0.313638;0.944914;,
  -0.095907;-0.000046;0.995390;,
  -0.097773;-0.313468;0.944552;,
  -0.099079;-0.592814;0.799222;,
  -0.099844;-0.810739;0.576830;,
  -0.100216;-0.948119;0.301708;,
  -0.100347;-0.994953;0.000000;,
  -0.100214;-0.948171;-0.301545;,
  -0.099843;-0.810838;-0.576691;,
  -0.099057;-0.592694;-0.799313;,
  -0.097709;-0.313327;-0.944605;,
  -0.095817;-0.000046;-0.995399;,
  -0.093568;0.313497;-0.944968;,
  -0.091221;0.593347;-0.799761;,
  -0.089136;0.811565;-0.577423;,
  -0.087698;0.949246;-0.302061;,
  -0.087180;0.996193;-0.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.577350;-0.577351;-0.577350;,
  0.577350;-0.577351;-0.577350;,
  -0.577366;0.577320;-0.577366;,
  0.577366;0.577320;-0.577366;,
  -0.577366;0.577320;0.577366;,
  0.577366;0.577320;0.577366;,
  -0.577350;-0.577351;0.577350;,
  0.577350;-0.577351;0.577350;,
  -0.707150;0.707063;0.000000;,
  0.707107;0.000042;0.707107;,
  0.000000;-0.707107;0.707106;,
  -0.707107;0.000042;0.707107;,
  0.707106;-0.707107;-0.000000;,
  -0.707106;-0.707107;0.000000;,
  0.000000;-0.707107;-0.707106;,
  0.707107;0.000042;-0.707107;,
  0.000000;0.707063;-0.707150;,
  -0.707107;0.000042;-0.707107;,
  0.707150;0.707063;0.000000;,
  0.000000;0.707063;0.707150;,
  0.000000;0.000041;-1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000041;1.000000;,
  0.000000;-1.000000;-0.000000;,
  1.000000;0.000041;0.000000;,
  -1.000000;0.000041;0.000000;;
  184;
  4;0,11,12,1;,
  4;1,12,13,2;,
  4;2,13,14,3;,
  4;3,14,15,4;,
  4;5,16,17,6;,
  4;6,17,18,7;,
  4;7,18,19,8;,
  4;8,19,20,9;,
  4;9,20,21,10;,
  4;10,21,11,0;,
  4;11,22,23,12;,
  4;12,23,24,13;,
  4;13,24,25,14;,
  4;14,25,26,15;,
  4;16,27,28,17;,
  4;17,28,29,18;,
  4;18,29,30,19;,
  4;19,30,31,20;,
  4;20,31,32,21;,
  4;21,32,22,11;,
  4;22,33,34,23;,
  4;23,34,35,24;,
  4;24,35,36,25;,
  4;25,36,37,26;,
  4;27,38,39,28;,
  4;28,39,40,29;,
  4;29,40,41,30;,
  4;30,41,42,31;,
  4;31,42,43,32;,
  4;32,43,33,22;,
  4;33,44,45,34;,
  4;34,45,46,35;,
  4;35,46,47,36;,
  4;36,47,48,37;,
  4;38,49,50,39;,
  4;39,50,51,40;,
  4;40,51,52,41;,
  4;41,52,53,42;,
  4;42,53,54,43;,
  4;43,54,44,33;,
  4;44,55,56,45;,
  4;45,56,57,46;,
  4;46,57,58,47;,
  4;47,58,59,48;,
  4;49,60,61,50;,
  4;50,61,62,51;,
  4;51,62,63,52;,
  4;52,63,64,53;,
  4;53,64,65,54;,
  4;54,65,55,44;,
  4;55,66,67,56;,
  4;56,67,68,57;,
  4;57,68,69,58;,
  4;58,69,70,59;,
  4;60,71,72,61;,
  4;61,72,73,62;,
  4;62,73,74,63;,
  4;63,74,75,64;,
  4;64,75,76,65;,
  4;65,76,66,55;,
  4;66,77,78,67;,
  4;67,78,79,68;,
  4;68,79,80,69;,
  4;69,80,81,70;,
  4;71,82,83,72;,
  4;72,83,84,73;,
  4;73,84,85,74;,
  4;74,85,86,75;,
  4;75,86,87,76;,
  4;76,87,77,66;,
  4;77,88,89,78;,
  4;78,89,90,79;,
  4;79,90,91,80;,
  4;80,91,92,81;,
  4;82,93,94,83;,
  4;83,94,95,84;,
  4;84,95,96,85;,
  4;85,96,97,86;,
  4;86,97,98,87;,
  4;87,98,88,77;,
  3;1,99,0;,
  3;2,99,1;,
  3;3,99,2;,
  3;4,99,3;,
  3;6,99,5;,
  3;7,99,6;,
  3;8,99,7;,
  3;9,99,8;,
  3;10,99,9;,
  3;0,99,10;,
  3;88,100,89;,
  3;89,100,90;,
  3;90,100,91;,
  3;91,100,92;,
  3;93,100,94;,
  3;94,100,95;,
  3;95,100,96;,
  3;96,100,97;,
  3;97,100,98;,
  3;98,100,88;,
  4;101,101,102,102;,
  4;102,102,103,103;,
  4;103,103,104,104;,
  4;104,104,105,105;,
  4;105,105,106,106;,
  4;106,106,107,107;,
  4;107,107,108,108;,
  4;108,108,109,109;,
  4;109,109,110,110;,
  4;110,110,111,111;,
  4;111,111,112,112;,
  4;112,112,113,113;,
  4;113,113,114,114;,
  4;114,114,115,115;,
  4;115,115,116,116;,
  4;116,116,117,117;,
  4;117,117,118,118;,
  4;118,118,119,119;,
  4;119,119,120,120;,
  4;120,120,101,101;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;121,121,121;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  3;122,122,122;,
  4;123,140,143,137;,
  4;137,143,138,124;,
  4;143,139,126,138;,
  4;140,125,139,143;,
  4;125,131,144,139;,
  4;139,144,141,126;,
  4;144,142,128,141;,
  4;131,127,142,144;,
  4;127,134,145,142;,
  4;142,145,132,128;,
  4;145,133,130,132;,
  4;134,129,133,145;,
  4;129,136,146,133;,
  4;133,146,135,130;,
  4;146,137,124,135;,
  4;136,123,137,146;,
  4;124,138,147,135;,
  4;135,147,132,130;,
  4;147,141,128,132;,
  4;138,126,141,147;,
  4;129,134,148,136;,
  4;136,148,140,123;,
  4;148,131,125,140;,
  4;134,127,131,148;;
 }
 MeshTextureCoords {
  251;
  0.000000;0.100000;,
  0.000000;0.200000;,
  0.050000;0.200000;,
  0.050000;0.100000;,
  0.100000;0.200000;,
  0.100000;0.100000;,
  0.150000;0.200000;,
  0.150000;0.100000;,
  0.200000;0.200000;,
  0.200000;0.100000;,
  0.700000;0.100000;,
  0.700000;0.200000;,
  0.750000;0.200000;,
  0.750000;0.100000;,
  0.800000;0.200000;,
  0.800000;0.100000;,
  0.850000;0.200000;,
  0.850000;0.100000;,
  0.900000;0.200000;,
  0.900000;0.100000;,
  0.950000;0.200000;,
  0.950000;0.100000;,
  1.000000;0.200000;,
  1.000000;0.100000;,
  0.000000;0.300000;,
  0.050000;0.300000;,
  0.100000;0.300000;,
  0.150000;0.300000;,
  0.200000;0.300000;,
  0.700000;0.300000;,
  0.750000;0.300000;,
  0.800000;0.300000;,
  0.850000;0.300000;,
  0.900000;0.300000;,
  0.950000;0.300000;,
  1.000000;0.300000;,
  0.000000;0.400000;,
  0.050000;0.400000;,
  0.100000;0.400000;,
  0.150000;0.400000;,
  0.200000;0.400000;,
  0.700000;0.400000;,
  0.750000;0.400000;,
  0.800000;0.400000;,
  0.850000;0.400000;,
  0.900000;0.400000;,
  0.950000;0.400000;,
  1.000000;0.400000;,
  0.000000;0.500000;,
  0.050000;0.500000;,
  0.100000;0.500000;,
  0.150000;0.500000;,
  0.200000;0.500000;,
  0.700000;0.500000;,
  0.750000;0.500000;,
  0.800000;0.500000;,
  0.850000;0.500000;,
  0.900000;0.500000;,
  0.950000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.600000;,
  0.050000;0.600000;,
  0.100000;0.600000;,
  0.150000;0.600000;,
  0.200000;0.600000;,
  0.700000;0.600000;,
  0.750000;0.600000;,
  0.800000;0.600000;,
  0.850000;0.600000;,
  0.900000;0.600000;,
  0.950000;0.600000;,
  1.000000;0.600000;,
  0.000000;0.700000;,
  0.050000;0.700000;,
  0.100000;0.700000;,
  0.150000;0.700000;,
  0.200000;0.700000;,
  0.700000;0.700000;,
  0.750000;0.700000;,
  0.800000;0.700000;,
  0.850000;0.700000;,
  0.900000;0.700000;,
  0.950000;0.700000;,
  1.000000;0.700000;,
  0.000000;0.800000;,
  0.050000;0.800000;,
  0.100000;0.800000;,
  0.150000;0.800000;,
  0.200000;0.800000;,
  0.700000;0.800000;,
  0.750000;0.800000;,
  0.800000;0.800000;,
  0.850000;0.800000;,
  0.900000;0.800000;,
  0.950000;0.800000;,
  1.000000;0.800000;,
  0.000000;0.900000;,
  0.050000;0.900000;,
  0.100000;0.900000;,
  0.150000;0.900000;,
  0.200000;0.900000;,
  0.700000;0.900000;,
  0.750000;0.900000;,
  0.800000;0.900000;,
  0.850000;0.900000;,
  0.900000;0.900000;,
  0.950000;0.900000;,
  1.000000;0.900000;,
  0.025000;0.000000;,
  0.075000;0.000000;,
  0.125000;0.000000;,
  0.175000;0.000000;,
  0.725000;0.000000;,
  0.775000;0.000000;,
  0.825000;0.000000;,
  0.875000;0.000000;,
  0.925000;0.000000;,
  0.975000;0.000000;,
  0.025000;1.000000;,
  0.075000;1.000000;,
  0.125000;1.000000;,
  0.175000;1.000000;,
  0.725000;1.000000;,
  0.775000;1.000000;,
  0.825000;1.000000;,
  0.875000;1.000000;,
  0.925000;1.000000;,
  0.975000;1.000000;,
  0.375000;0.312500;,
  0.375000;0.688440;,
  0.387500;0.688440;,
  0.387500;0.312500;,
  0.400000;0.688440;,
  0.400000;0.312500;,
  0.412500;0.688440;,
  0.412500;0.312500;,
  0.425000;0.688440;,
  0.425000;0.312500;,
  0.437500;0.688440;,
  0.437500;0.312500;,
  0.450000;0.688440;,
  0.450000;0.312500;,
  0.462500;0.688440;,
  0.462500;0.312500;,
  0.475000;0.688440;,
  0.475000;0.312500;,
  0.487500;0.688440;,
  0.487500;0.312500;,
  0.500000;0.688440;,
  0.500000;0.312500;,
  0.512500;0.688440;,
  0.512500;0.312500;,
  0.525000;0.688440;,
  0.525000;0.312500;,
  0.537500;0.688440;,
  0.537500;0.312500;,
  0.550000;0.688440;,
  0.550000;0.312500;,
  0.562500;0.688440;,
  0.562500;0.312500;,
  0.575000;0.688440;,
  0.575000;0.312500;,
  0.587500;0.688440;,
  0.587500;0.312500;,
  0.600000;0.688440;,
  0.600000;0.312500;,
  0.612500;0.688440;,
  0.612500;0.312500;,
  0.625000;0.688440;,
  0.625000;0.312500;,
  0.626410;0.064410;,
  0.500000;0.150000;,
  0.648600;0.107970;,
  0.591840;0.029840;,
  0.548280;0.007650;,
  0.500000;-0.000000;,
  0.451720;0.007650;,
  0.408160;0.029840;,
  0.373590;0.064410;,
  0.351400;0.107970;,
  0.343750;0.156250;,
  0.351400;0.204530;,
  0.373590;0.248090;,
  0.408160;0.282660;,
  0.451720;0.304850;,
  0.500000;0.312500;,
  0.548280;0.304850;,
  0.591840;0.282660;,
  0.626410;0.248090;,
  0.648600;0.204530;,
  0.656250;0.156250;,
  0.648600;0.892030;,
  0.500000;0.837500;,
  0.626410;0.935590;,
  0.591840;0.970160;,
  0.548280;0.992350;,
  0.500000;1.000000;,
  0.451720;0.992350;,
  0.408160;0.970160;,
  0.373590;0.935590;,
  0.351400;0.892030;,
  0.343750;0.843750;,
  0.351400;0.795470;,
  0.373590;0.751910;,
  0.408160;0.717340;,
  0.451720;0.695150;,
  0.500000;0.687500;,
  0.548280;0.695150;,
  0.591840;0.717340;,
  0.626410;0.751910;,
  0.648600;0.795470;,
  0.656250;0.843750;,
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
