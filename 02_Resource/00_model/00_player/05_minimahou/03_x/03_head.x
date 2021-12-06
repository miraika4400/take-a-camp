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
 254;
 -1.07320;1.79720;-1.18880;,
 -1.41430;3.92450;-1.97670;,
 0.00490;3.84520;-2.54690;,
 0.00490;1.29360;-1.36560;,
 1.42390;3.92450;-1.97670;,
 1.08270;1.79720;-1.18880;,
 0.00490;4.70225;-1.72720;,
 1.28420;4.93400;-1.27930;,
 -1.27460;4.93400;-1.27930;,
 -1.27460;4.93400;1.27930;,
 -1.72250;3.42900;1.72720;,
 0.00490;3.42900;2.30280;,
 0.00490;4.80638;1.72720;,
 1.73200;3.42900;1.72720;,
 1.57740;4.59896;1.57750;,
 0.00490;1.85710;1.62830;,
 1.28420;1.92410;1.27930;,
 -1.27460;1.92410;1.27930;,
 -1.30390;1.39730;0.00000;,
 0.00490;0.72010;0.00000;,
 1.31340;1.39730;0.00000;,
 0.00490;1.29360;-1.36560;,
 1.08270;1.79720;-1.18880;,
 -1.07320;1.79720;-1.18880;,
 2.30770;3.42900;0.00000;,
 1.31340;1.39730;0.00000;,
 1.73200;3.42900;1.72720;,
 1.28420;1.92410;1.27930;,
 1.73200;5.00440;0.00000;,
 1.57740;4.59896;1.57750;,
 -1.27460;1.92410;1.27930;,
 -1.72250;3.42900;1.72720;,
 -2.29820;3.42900;0.00000;,
 -1.30390;1.39730;0.00000;,
 -1.72250;4.73826;0.00000;,
 -1.27460;4.93400;1.27930;,
 2.19850;4.04078;0.97890;,
 3.78050;3.82818;1.69180;,
 2.76380;3.82818;3.09100;,
 1.61020;4.04078;1.78860;,
 1.26600;3.82818;3.95580;,
 0.74350;4.04078;2.28900;,
 -0.45410;3.82818;4.13660;,
 -0.25190;4.04078;2.39360;,
 -2.09920;3.82818;3.60220;,
 -1.20360;4.04078;2.08440;,
 -3.38440;3.82818;2.44480;,
 -1.94730;4.04078;1.41470;,
 -4.08790;3.82818;0.86480;,
 -2.35440;4.04078;0.50040;,
 -4.08790;3.82818;-0.86480;,
 -2.35440;4.04078;-0.50040;,
 -3.38440;3.82818;-2.44480;,
 -1.94730;4.04078;-1.41470;,
 -2.09920;3.82818;-3.60220;,
 -1.20360;4.04078;-2.08440;,
 -0.45420;3.82818;-4.13660;,
 -0.25190;4.04078;-2.39360;,
 1.26600;3.82818;-3.95580;,
 0.74350;4.04078;-2.28900;,
 2.76380;3.82818;-3.09100;,
 1.61020;4.04078;-1.78860;,
 3.78050;3.82818;-1.69180;,
 2.19850;4.04078;-0.97890;,
 4.14000;3.82818;0.00000;,
 2.40650;4.04078;0.00000;,
 3.78050;3.82818;1.69180;,
 2.19850;4.04078;0.97890;,
 1.15780;5.28720;0.50990;,
 0.85140;5.28720;0.93170;,
 0.39980;5.28720;1.19250;,
 -0.11860;5.28720;1.24700;,
 -0.61460;5.28720;1.08580;,
 -1.00190;5.28720;0.73700;,
 -1.21400;5.28720;0.26070;,
 -1.21400;5.28720;-0.26070;,
 -1.00190;5.28720;-0.73700;,
 -0.61460;5.28720;-1.08580;,
 -0.11860;5.28720;-1.24700;,
 0.39980;5.28720;-1.19250;,
 0.85140;5.28720;-0.93170;,
 1.15780;5.28720;-0.50990;,
 1.26610;5.28720;0.00000;,
 1.15780;5.28720;0.50990;,
 0.99060;5.53450;0.43460;,
 0.72940;5.53450;0.79420;,
 0.34460;5.53450;1.01630;,
 -0.09730;5.53450;1.06280;,
 -0.52000;5.53450;0.92550;,
 -0.85010;5.53450;0.62820;,
 -1.03090;5.53450;0.22220;,
 -1.03090;5.53450;-0.22220;,
 -0.85010;5.53450;-0.62820;,
 -0.52000;5.53450;-0.92550;,
 -0.09730;5.53450;-1.06280;,
 0.34460;5.53450;-1.01630;,
 0.72940;5.53450;-0.79420;,
 0.99060;5.53450;-0.43460;,
 1.08300;5.53450;0.00000;,
 0.99060;5.53450;0.43460;,
 0.77560;6.67590;0.54890;,
 0.57260;6.54060;0.79340;,
 0.27350;6.45690;0.94430;,
 -0.06990;6.43940;0.97600;,
 -0.39820;6.49110;0.88260;,
 -0.65480;6.60300;0.68050;,
 -0.53420;6.85930;0.41520;,
 -0.79530;6.92310;0.10250;,
 -0.65480;7.07590;-0.17340;,
 -0.39820;7.18790;-0.37560;,
 -0.06990;7.23950;-0.46890;,
 0.27350;7.22200;-0.43740;,
 0.57260;7.13840;-0.28630;,
 0.77560;7.00310;-0.04190;,
 0.84740;6.83950;0.25350;,
 0.77560;6.67590;0.54890;,
 0.77560;6.96640;0.70990;,
 0.57260;6.83110;0.95430;,
 0.27350;6.74740;1.10530;,
 -0.06990;6.73000;1.13680;,
 -0.39820;6.78170;1.04350;,
 -0.65480;6.89350;0.84130;,
 -0.79530;7.04640;0.56540;,
 -0.79530;7.21370;0.26340;,
 -0.65480;7.36650;-0.01260;,
 -0.39820;7.47840;-0.21460;,
 -0.06990;7.53010;-0.30800;,
 0.27350;7.51260;-0.27640;,
 0.57260;7.42890;-0.12540;,
 0.77560;7.29360;0.11900;,
 0.84740;7.13010;0.41450;,
 0.77560;6.96640;0.70990;,
 1.61020;4.04078;1.78860;,
 0.01570;4.06368;0.00000;,
 2.19850;4.04078;0.97890;,
 0.74350;4.04078;2.28900;,
 -0.25190;4.04078;2.39360;,
 -1.20360;4.04078;2.08440;,
 -1.94730;4.04078;1.41470;,
 -2.35440;4.04078;0.50040;,
 -2.35440;4.04078;-0.50040;,
 -1.94730;4.04078;-1.41470;,
 -1.20360;4.04078;-2.08440;,
 -0.25190;4.04078;-2.39360;,
 0.74350;4.04078;-2.28900;,
 1.61020;4.04078;-1.78860;,
 2.19850;4.04078;-0.97890;,
 2.40650;4.04078;0.00000;,
 0.04010;8.55580;2.30070;,
 0.02590;8.56160;2.29810;,
 0.03630;8.55100;2.30270;,
 0.03070;8.54800;2.30400;,
 0.02430;8.54740;2.30430;,
 0.01800;8.54920;2.30350;,
 0.01330;8.55320;2.30180;,
 0.01070;8.55860;2.29950;,
 0.01070;8.56450;2.29680;,
 0.01330;8.57000;2.29450;,
 0.01800;8.57410;2.29270;,
 0.02430;8.57590;2.29200;,
 0.03070;8.57530;2.29230;,
 0.03630;8.57220;2.29360;,
 0.04010;8.56740;2.29560;,
 0.04140;8.56160;2.29810;,
 0.77560;6.96640;0.70990;,
 0.44970;7.97750;1.35250;,
 0.33490;7.90100;1.49050;,
 0.57260;6.83110;0.95430;,
 0.16590;7.85380;1.57600;,
 0.27350;6.74740;1.10530;,
 -0.02810;7.84390;1.59380;,
 -0.06990;6.73000;1.13680;,
 -0.21370;7.87310;1.54110;,
 -0.39820;6.78170;1.04350;,
 -0.35870;7.93630;1.42680;,
 -0.65480;6.89350;0.84130;,
 -0.43800;8.02270;1.27080;,
 -0.79530;7.04640;0.56540;,
 -0.43800;8.11720;1.10020;,
 -0.79530;7.21370;0.26340;,
 -0.35870;8.20360;0.94420;,
 -0.65480;7.36650;-0.01260;,
 -0.21370;8.26680;0.83000;,
 -0.39820;7.47840;-0.21460;,
 -0.02810;8.29600;0.77720;,
 -0.06990;7.53010;-0.30800;,
 0.16590;8.28620;0.79510;,
 0.27350;7.51260;-0.27640;,
 0.33490;8.23880;0.88040;,
 0.57260;7.42890;-0.12540;,
 0.44970;8.16240;1.01860;,
 0.77560;7.29360;0.11900;,
 0.49020;8.06990;1.18550;,
 0.84740;7.13010;0.41450;,
 0.22050;0.35380;0.10830;,
 0.22050;0.85240;0.10830;,
 0.15130;0.85240;0.19500;,
 0.15130;0.35380;0.19500;,
 0.05120;0.85240;0.24310;,
 0.05120;0.35380;0.24310;,
 -0.05970;0.85240;0.24310;,
 -0.05970;0.35380;0.24310;,
 -0.15960;0.85240;0.19500;,
 -0.15960;0.35380;0.19500;,
 -0.22890;0.85240;0.10830;,
 -0.22890;0.35380;0.10830;,
 -0.25360;0.85240;0.00000;,
 -0.25360;0.35380;0.00000;,
 -0.22890;0.85240;-0.10830;,
 -0.22890;0.35380;-0.10830;,
 -0.15960;0.85240;-0.19500;,
 -0.15960;0.35380;-0.19500;,
 -0.05970;0.85240;-0.24310;,
 -0.05970;0.35380;-0.24310;,
 0.05120;0.85240;-0.24310;,
 0.05120;0.35380;-0.24310;,
 0.15130;0.85240;-0.19500;,
 0.15130;0.35380;-0.19500;,
 0.22050;0.85240;-0.10830;,
 0.22050;0.35380;-0.10830;,
 0.24520;0.85240;0.00000;,
 0.24520;0.35380;0.00000;,
 0.22050;0.85240;0.10830;,
 0.22050;0.35380;0.10830;,
 0.15130;0.35380;0.19500;,
 -0.00430;0.35380;0.00000;,
 0.22050;0.35380;0.10830;,
 0.05120;0.35380;0.24310;,
 -0.05970;0.35380;0.24310;,
 -0.15960;0.35380;0.19500;,
 -0.22890;0.35380;0.10830;,
 -0.25360;0.35380;0.00000;,
 -0.22890;0.35380;-0.10830;,
 -0.15960;0.35380;-0.19500;,
 -0.05970;0.35380;-0.24310;,
 0.05120;0.35380;-0.24310;,
 0.15130;0.35380;-0.19500;,
 0.22050;0.35380;-0.10830;,
 0.24520;0.35380;0.00000;,
 0.22050;0.85240;0.10830;,
 -0.00430;0.85240;0.00000;,
 0.15130;0.85240;0.19500;,
 0.05120;0.85240;0.24310;,
 -0.05970;0.85240;0.24310;,
 -0.15960;0.85240;0.19500;,
 -0.22890;0.85240;0.10830;,
 -0.25360;0.85240;0.00000;,
 -0.22890;0.85240;-0.10830;,
 -0.15960;0.85240;-0.19500;,
 -0.05970;0.85240;-0.24310;,
 0.05120;0.85240;-0.24310;,
 0.15130;0.85240;-0.19500;,
 0.22050;0.85240;-0.10830;,
 0.24520;0.85240;0.00000;;
 
 197;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;2,6,7,4;,
 4;1,8,6,2;,
 4;9,10,11,12;,
 4;12,11,13,14;,
 4;11,15,16,13;,
 4;10,17,15,11;,
 4;17,18,19,15;,
 4;15,19,20,16;,
 4;19,21,22,20;,
 4;18,23,21,19;,
 4;5,4,24,25;,
 4;25,24,26,27;,
 4;24,28,29,26;,
 4;4,7,28,24;,
 4;30,31,32,33;,
 4;33,32,1,0;,
 4;32,34,8,1;,
 4;31,35,34,32;,
 4;36,37,38,39;,
 4;39,38,40,41;,
 4;41,40,42,43;,
 4;43,42,44,45;,
 4;45,44,46,47;,
 4;47,46,48,49;,
 4;49,48,50,51;,
 4;51,50,52,53;,
 4;53,52,54,55;,
 4;55,54,56,57;,
 4;57,56,58,59;,
 4;59,58,60,61;,
 4;61,60,62,63;,
 4;63,62,64,65;,
 4;65,64,66,67;,
 4;37,68,69,38;,
 4;38,69,70,40;,
 4;40,70,71,42;,
 4;42,71,72,44;,
 4;44,72,73,46;,
 4;46,73,74,48;,
 4;48,74,75,50;,
 4;50,75,76,52;,
 4;52,76,77,54;,
 4;54,77,78,56;,
 4;56,78,79,58;,
 4;58,79,80,60;,
 4;60,80,81,62;,
 4;62,81,82,64;,
 4;64,82,83,66;,
 4;68,84,85,69;,
 4;69,85,86,70;,
 4;70,86,87,71;,
 4;71,87,88,72;,
 4;72,88,89,73;,
 4;73,89,90,74;,
 4;74,90,91,75;,
 4;75,91,92,76;,
 4;76,92,93,77;,
 4;77,93,94,78;,
 4;78,94,95,79;,
 4;79,95,96,80;,
 4;80,96,97,81;,
 4;81,97,98,82;,
 4;82,98,99,83;,
 4;84,100,101,85;,
 4;85,101,102,86;,
 4;86,102,103,87;,
 4;87,103,104,88;,
 4;88,104,105,89;,
 4;89,105,106,90;,
 4;90,106,107,91;,
 4;91,107,108,92;,
 4;92,108,109,93;,
 4;93,109,110,94;,
 4;94,110,111,95;,
 4;95,111,112,96;,
 4;96,112,113,97;,
 4;97,113,114,98;,
 4;98,114,115,99;,
 4;100,116,117,101;,
 4;101,117,118,102;,
 4;102,118,119,103;,
 4;103,119,120,104;,
 4;104,120,121,105;,
 4;105,121,122,106;,
 4;106,122,123,107;,
 4;107,123,124,108;,
 4;108,124,125,109;,
 4;109,125,126,110;,
 4;110,126,127,111;,
 4;111,127,128,112;,
 4;112,128,129,113;,
 4;113,129,130,114;,
 4;114,130,131,115;,
 3;132,133,134;,
 3;135,133,132;,
 3;136,133,135;,
 3;137,133,136;,
 3;138,133,137;,
 3;139,133,138;,
 3;140,133,139;,
 3;141,133,140;,
 3;142,133,141;,
 3;143,133,142;,
 3;144,133,143;,
 3;145,133,144;,
 3;146,133,145;,
 3;147,133,146;,
 3;134,133,147;,
 3;148,149,150;,
 3;150,149,151;,
 3;151,149,152;,
 3;152,149,153;,
 3;153,149,154;,
 3;154,149,155;,
 3;155,149,156;,
 3;156,149,157;,
 3;157,149,158;,
 3;158,149,159;,
 3;159,149,160;,
 3;160,149,161;,
 3;161,149,162;,
 3;162,149,163;,
 3;163,149,148;,
 4;164,165,166,167;,
 4;167,166,168,169;,
 4;169,168,170,171;,
 4;171,170,172,173;,
 4;173,172,174,175;,
 4;175,174,176,177;,
 4;177,176,178,179;,
 4;179,178,180,181;,
 4;181,180,182,183;,
 4;183,182,184,185;,
 4;185,184,186,187;,
 4;187,186,188,189;,
 4;189,188,190,191;,
 4;191,190,192,193;,
 4;193,192,165,164;,
 4;165,148,150,166;,
 4;166,150,151,168;,
 4;168,151,152,170;,
 4;170,152,153,172;,
 4;172,153,154,174;,
 4;174,154,155,176;,
 4;176,155,156,178;,
 4;178,156,157,180;,
 4;180,157,158,182;,
 4;182,158,159,184;,
 4;184,159,160,186;,
 4;186,160,161,188;,
 4;188,161,162,190;,
 4;190,162,163,192;,
 4;192,163,148,165;,
 4;194,195,196,197;,
 4;197,196,198,199;,
 4;199,198,200,201;,
 4;201,200,202,203;,
 4;203,202,204,205;,
 4;205,204,206,207;,
 4;207,206,208,209;,
 4;209,208,210,211;,
 4;211,210,212,213;,
 4;213,212,214,215;,
 4;215,214,216,217;,
 4;217,216,218,219;,
 4;219,218,220,221;,
 4;221,220,222,223;,
 3;224,225,226;,
 3;227,225,224;,
 3;228,225,227;,
 3;229,225,228;,
 3;230,225,229;,
 3;231,225,230;,
 3;232,225,231;,
 3;233,225,232;,
 3;234,225,233;,
 3;235,225,234;,
 3;236,225,235;,
 3;237,225,236;,
 3;238,225,237;,
 3;226,225,238;,
 3;239,240,241;,
 3;241,240,242;,
 3;242,240,243;,
 3;243,240,244;,
 3;244,240,245;,
 3;245,240,246;,
 3;246,240,247;,
 3;247,240,248;,
 3;248,240,249;,
 3;249,240,250;,
 3;250,240,251;,
 3;251,240,252;,
 3;252,240,253;,
 3;253,240,239;;
 
 MeshMaterialList {
  2;
  197;
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
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
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
   0.800000;0.520000;0.232000;1.000000;;
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
  197;
  -0.589109;-0.568511;-0.574235;,
  0.589154;-0.568492;-0.574207;,
  -0.608829;0.548561;-0.573069;,
  0.607187;0.528884;-0.592964;,
  -0.650219;0.401097;0.645241;,
  0.668765;0.302776;0.679028;,
  -0.549634;-0.588771;0.592665;,
  0.549677;-0.588754;0.592641;,
  -0.924911;0.380178;-0.002281;,
  0.267236;-0.048748;0.962397;,
  0.000028;-0.662626;0.748950;,
  -0.572032;0.140912;0.808037;,
  0.718567;-0.695419;-0.007256;,
  -0.718535;-0.695453;-0.007249;,
  0.000044;-0.708000;-0.706213;,
  0.791101;-0.157992;-0.590929;,
  0.000015;0.639192;-0.769047;,
  -0.799519;-0.146991;-0.582377;,
  0.951697;0.304594;-0.038660;,
  -0.030648;0.327929;0.944205;,
  0.000033;-0.411038;-0.911618;,
  -0.016424;-0.027762;0.999480;,
  0.000045;-0.997871;0.065220;,
  0.997169;-0.047749;-0.058086;,
  -0.999210;-0.006822;-0.039163;,
  -0.060014;-0.997840;-0.026705;,
  -0.043858;-0.997851;-0.048676;,
  -0.020198;-0.997867;-0.062068;,
  0.006762;-0.997886;-0.064637;,
  0.032337;-0.997903;-0.056061;,
  0.052181;-0.997917;-0.037932;,
  0.062988;-0.997924;-0.013396;,
  0.062988;-0.997924;0.013396;,
  0.052181;-0.997917;0.037932;,
  0.032337;-0.997904;0.056061;,
  0.006762;-0.997886;0.064636;,
  -0.020198;-0.997867;0.062068;,
  -0.043858;-0.997851;0.048676;,
  -0.060014;-0.997840;0.026705;,
  -0.065749;-0.997836;0.000000;,
  -0.111110;-0.992577;-0.049441;,
  -0.081195;-0.992616;-0.090112;,
  -0.037391;-0.992674;-0.114894;,
  0.012514;-0.992739;-0.119636;,
  0.059845;-0.992801;-0.103753;,
  0.096563;-0.992849;-0.070195;,
  0.116557;-0.992875;-0.024789;,
  0.116557;-0.992875;0.024789;,
  0.096563;-0.992849;0.070195;,
  0.059845;-0.992801;0.103752;,
  0.012514;-0.992739;0.119635;,
  -0.037391;-0.992674;0.114894;,
  -0.081195;-0.992616;0.090112;,
  -0.111110;-0.992577;0.049441;,
  -0.121730;-0.992563;0.000000;,
  0.588536;0.764872;0.261908;,
  0.430543;0.765638;0.477946;,
  0.198540;0.766764;0.610455;,
  -0.066772;0.768025;0.636930;,
  -0.319419;0.769191;0.553459;,
  -0.516027;0.770117;0.375014;,
  -0.623335;0.770639;0.132547;,
  -0.623335;0.770639;-0.132547;,
  -0.516027;0.770117;-0.375014;,
  -0.319420;0.769192;-0.553458;,
  -0.066773;0.768025;-0.636929;,
  0.198539;0.766764;-0.610454;,
  0.430543;0.765638;-0.477946;,
  0.588536;0.764872;-0.261908;,
  0.644522;0.764586;0.000000;,
  0.837871;0.371966;0.399517;,
  0.607768;0.360170;0.707740;,
  0.277502;0.357843;0.891595;,
  -0.093378;0.359051;0.928635;,
  -0.450503;0.361648;0.816246;,
  -0.762828;0.412544;0.497896;,
  -0.879650;0.422724;0.217990;,
  -0.898177;0.429600;-0.093392;,
  -0.732870;0.441661;-0.517529;,
  -0.448902;0.461875;-0.764956;,
  -0.093334;0.470659;-0.877365;,
  0.276938;0.466105;-0.840269;,
  0.604545;0.449007;-0.657965;,
  0.833769;0.422990;-0.354837;,
  0.918611;0.394616;0.020802;,
  0.912766;-0.038255;0.406687;,
  0.670389;-0.136004;0.729439;,
  0.310163;-0.193234;0.930838;,
  -0.104959;-0.204359;0.973253;,
  -0.501545;-0.168880;0.848488;,
  -0.913217;-0.104786;0.393771;,
  -0.985448;-0.127406;0.112519;,
  -0.997265;0.016384;-0.072071;,
  -0.801791;0.274110;-0.531032;,
  -0.494184;0.364846;-0.789094;,
  -0.103166;0.407057;-0.907558;,
  0.305117;0.392391;-0.867717;,
  0.662242;0.323692;-0.675765;,
  0.907046;0.214394;-0.362356;,
  0.996114;0.085678;0.020390;,
  0.907662;-0.099984;0.407619;,
  0.666554;-0.288289;0.687455;,
  0.308215;-0.404853;0.860870;,
  -0.104324;-0.428707;0.897400;,
  -0.498478;-0.355625;0.790601;,
  -0.860827;-0.257472;0.438960;,
  -0.974619;-0.180707;0.132148;,
  -0.991602;0.106986;-0.072654;,
  -0.794159;0.449048;-0.409472;,
  -0.488861;0.597848;-0.635290;,
  -0.102052;0.665681;-0.739225;,
  0.301871;0.642206;-0.704589;,
  0.655647;0.530939;-0.536871;,
  0.899416;0.349000;-0.263154;,
  0.989504;0.125910;0.070920;,
  -0.000033;-1.000000;0.000000;,
  0.885713;-0.065716;0.459558;,
  0.657858;-0.342248;0.670887;,
  0.306502;-0.514403;0.800903;,
  -0.102088;-0.549993;0.828907;,
  -0.493384;-0.440401;0.750079;,
  -0.790719;-0.207552;0.575922;,
  -0.935817;0.097724;0.338670;,
  -0.910396;0.406116;0.079054;,
  -0.734706;0.661590;-0.150022;,
  -0.443694;0.840515;-0.310920;,
  -0.090089;0.919402;-0.382863;,
  0.273988;0.891958;-0.359640;,
  0.600616;0.761411;-0.243954;,
  0.839597;0.541415;-0.044124;,
  0.945787;0.251270;0.205794;,
  -0.004504;0.399884;0.916555;,
  -0.004597;0.394291;0.918974;,
  -0.000228;0.396468;0.918048;,
  0.002675;0.398789;0.917039;,
  0.001757;0.399996;0.916515;,
  0.001643;0.398391;0.917214;,
  0.006040;0.395498;0.918447;,
  0.004201;0.405401;0.914130;,
  -0.001616;0.402003;0.915637;,
  -0.000612;0.393134;0.919481;,
  -0.002996;0.394980;0.918685;,
  -0.008015;0.391583;0.920108;,
  -0.002344;0.390543;0.920582;,
  0.002902;0.388348;0.921508;,
  0.002045;0.391595;0.920136;,
  0.000000;0.402468;0.915434;,
  0.900914;0.000000;0.433997;,
  0.622992;0.000000;0.782228;,
  0.222103;0.000000;0.975023;,
  -0.222484;0.000000;0.974936;,
  -0.623022;0.000000;0.782204;,
  -0.900761;0.000000;0.434314;,
  -1.000000;0.000000;0.000000;,
  -0.900761;0.000000;-0.434314;,
  -0.623022;0.000000;-0.782204;,
  -0.222484;0.000000;-0.974936;,
  0.222103;0.000000;-0.975023;,
  0.622992;0.000000;-0.782228;,
  0.900914;0.000000;-0.433997;,
  1.000000;0.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.210309;0.624897;-0.751847;,
  -0.210280;0.624900;-0.751853;,
  0.962575;-0.074053;0.260704;,
  -0.885937;-0.392399;0.247263;,
  0.413267;0.891849;0.183889;,
  0.302142;0.892332;0.335341;,
  0.139224;0.893046;0.427884;,
  -0.046687;0.893862;0.445905;,
  -0.223282;0.894640;0.386995;,
  -0.360440;0.895235;0.261986;,
  -0.435201;0.895564;0.092551;,
  -0.435201;0.895564;-0.092551;,
  -0.360440;0.895235;-0.261986;,
  -0.223283;0.894640;-0.386993;,
  -0.046690;0.893863;-0.445902;,
  0.139223;0.893047;-0.427884;,
  0.302142;0.892332;-0.335341;,
  0.413267;0.891849;-0.183889;,
  0.452686;0.891670;0.000000;,
  0.876934;-0.129773;0.462759;,
  0.643682;-0.463619;0.608877;,
  0.295944;-0.663237;0.687411;,
  -0.096460;-0.703744;0.703874;,
  -0.478865;-0.578812;0.660049;,
  -0.780441;-0.302266;0.547310;,
  -0.924754;0.067796;0.374479;,
  -0.886442;0.430403;0.170218;,
  -0.702729;0.711418;-0.007447;,
  -0.415296;0.900890;-0.126199;,
  -0.081648;0.980783;-0.177195;,
  0.255985;0.953217;-0.160778;,
  0.567534;0.819526;-0.079261;,
  0.808186;0.584162;0.074765;,
  0.929063;0.252379;0.270457;;
  197;
  4;0,17,20,14;,
  4;14,20,15,1;,
  4;16,16,3,163;,
  4;164,2,16,16;,
  4;4,11,21,19;,
  4;19,21,9,5;,
  4;21,10,7,9;,
  4;11,6,10,21;,
  4;6,13,22,10;,
  4;10,22,12,7;,
  4;22,14,1,12;,
  4;13,0,14,22;,
  4;1,15,23,12;,
  4;12,23,165,7;,
  4;23,18,5,165;,
  4;15,3,18,23;,
  4;6,166,24,13;,
  4;13,24,17,0;,
  4;24,8,2,17;,
  4;11,4,8,24;,
  4;25,40,41,26;,
  4;26,41,42,27;,
  4;27,42,43,28;,
  4;28,43,44,29;,
  4;29,44,45,30;,
  4;30,45,46,31;,
  4;31,46,47,32;,
  4;32,47,48,33;,
  4;33,48,49,34;,
  4;34,49,50,35;,
  4;35,50,51,36;,
  4;36,51,52,37;,
  4;37,52,53,38;,
  4;38,53,54,39;,
  4;39,54,40,25;,
  4;167,55,56,168;,
  4;168,56,57,169;,
  4;169,57,58,170;,
  4;170,58,59,171;,
  4;171,59,60,172;,
  4;172,60,61,173;,
  4;173,61,62,174;,
  4;174,62,63,175;,
  4;175,63,64,176;,
  4;176,64,65,177;,
  4;177,65,66,178;,
  4;178,66,67,179;,
  4;179,67,68,180;,
  4;180,68,69,181;,
  4;181,69,55,167;,
  4;55,70,71,56;,
  4;56,71,72,57;,
  4;57,72,73,58;,
  4;58,73,74,59;,
  4;59,74,75,60;,
  4;60,75,76,61;,
  4;61,76,77,62;,
  4;62,77,78,63;,
  4;63,78,79,64;,
  4;64,79,80,65;,
  4;65,80,81,66;,
  4;66,81,82,67;,
  4;67,82,83,68;,
  4;68,83,84,69;,
  4;69,84,70,55;,
  4;70,85,86,71;,
  4;71,86,87,72;,
  4;72,87,88,73;,
  4;73,88,89,74;,
  4;74,89,90,75;,
  4;75,90,91,76;,
  4;76,91,92,77;,
  4;77,92,93,78;,
  4;78,93,94,79;,
  4;79,94,95,80;,
  4;80,95,96,81;,
  4;81,96,97,82;,
  4;82,97,98,83;,
  4;83,98,99,84;,
  4;84,99,85,70;,
  4;85,100,101,86;,
  4;86,101,102,87;,
  4;87,102,103,88;,
  4;88,103,104,89;,
  4;89,104,105,90;,
  4;90,105,106,91;,
  4;91,106,107,92;,
  4;92,107,108,93;,
  4;93,108,109,94;,
  4;94,109,110,95;,
  4;95,110,111,96;,
  4;96,111,112,97;,
  4;97,112,113,98;,
  4;98,113,114,99;,
  4;99,114,100,85;,
  3;26,115,25;,
  3;27,115,26;,
  3;28,115,27;,
  3;29,115,28;,
  3;30,115,29;,
  3;31,115,30;,
  3;32,115,31;,
  3;33,115,32;,
  3;34,115,33;,
  3;35,115,34;,
  3;36,115,35;,
  3;37,115,36;,
  3;38,115,37;,
  3;39,115,38;,
  3;25,115,39;,
  3;131,133,132;,
  3;132,133,134;,
  3;134,133,135;,
  3;135,133,136;,
  3;136,133,137;,
  3;137,133,138;,
  3;138,133,139;,
  3;139,133,140;,
  3;140,133,141;,
  3;141,133,142;,
  3;142,133,143;,
  3;143,133,144;,
  3;144,133,145;,
  3;145,133,146;,
  3;146,133,131;,
  4;100,116,117,101;,
  4;101,117,118,102;,
  4;102,118,119,103;,
  4;103,119,120,104;,
  4;104,120,121,105;,
  4;105,121,122,106;,
  4;106,122,123,107;,
  4;107,123,124,108;,
  4;108,124,125,109;,
  4;109,125,126,110;,
  4;110,126,127,111;,
  4;111,127,128,112;,
  4;112,128,129,113;,
  4;113,129,130,114;,
  4;114,130,116,100;,
  4;116,182,183,117;,
  4;117,183,184,118;,
  4;118,184,185,119;,
  4;119,185,186,120;,
  4;120,186,187,121;,
  4;121,187,188,122;,
  4;122,188,189,123;,
  4;123,189,190,124;,
  4;124,190,191,125;,
  4;125,191,192,126;,
  4;126,192,193,127;,
  4;127,193,194,128;,
  4;128,194,195,129;,
  4;129,195,196,130;,
  4;130,196,182,116;,
  4;147,147,148,148;,
  4;148,148,149,149;,
  4;149,149,150,150;,
  4;150,150,151,151;,
  4;151,151,152,152;,
  4;152,152,153,153;,
  4;153,153,154,154;,
  4;154,154,155,155;,
  4;155,155,156,156;,
  4;156,156,157,157;,
  4;157,157,158,158;,
  4;158,158,159,159;,
  4;159,159,160,160;,
  4;160,160,147,147;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;161,161,161;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;,
  3;162,162,162;;
 }
 MeshTextureCoords {
  254;
  0.375000;0.000000;,
  0.375000;0.125000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.500000;0.500000;,
  0.625000;0.625000;,
  0.625000;0.500000;,
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
  0.375000;0.312500;,
  0.375000;0.387690;,
  0.391670;0.387690;,
  0.391670;0.312500;,
  0.408330;0.387690;,
  0.408330;0.312500;,
  0.425000;0.387690;,
  0.425000;0.312500;,
  0.441670;0.387690;,
  0.441670;0.312500;,
  0.458330;0.387690;,
  0.458330;0.312500;,
  0.475000;0.387690;,
  0.475000;0.312500;,
  0.491670;0.387690;,
  0.491670;0.312500;,
  0.508330;0.387690;,
  0.508330;0.312500;,
  0.525000;0.387690;,
  0.525000;0.312500;,
  0.541670;0.387690;,
  0.541670;0.312500;,
  0.558330;0.387690;,
  0.558330;0.312500;,
  0.575000;0.387690;,
  0.575000;0.312500;,
  0.591670;0.387690;,
  0.591670;0.312500;,
  0.608330;0.387690;,
  0.608330;0.312500;,
  0.625000;0.387690;,
  0.625000;0.312500;,
  0.375000;0.462880;,
  0.391670;0.462880;,
  0.408330;0.462880;,
  0.425000;0.462880;,
  0.441670;0.462880;,
  0.458330;0.462880;,
  0.475000;0.462880;,
  0.491670;0.462880;,
  0.508330;0.462880;,
  0.525000;0.462880;,
  0.541670;0.462880;,
  0.558330;0.462880;,
  0.575000;0.462880;,
  0.591670;0.462880;,
  0.608330;0.462880;,
  0.625000;0.462880;,
  0.375000;0.538060;,
  0.391670;0.538060;,
  0.408330;0.538060;,
  0.425000;0.538060;,
  0.441670;0.538060;,
  0.458330;0.538060;,
  0.475000;0.538060;,
  0.491670;0.538060;,
  0.508330;0.538060;,
  0.525000;0.538060;,
  0.541670;0.538060;,
  0.558330;0.538060;,
  0.575000;0.538060;,
  0.591670;0.538060;,
  0.608330;0.538060;,
  0.625000;0.538060;,
  0.375000;0.613250;,
  0.391670;0.613250;,
  0.408330;0.613250;,
  0.425000;0.613250;,
  0.441670;0.613250;,
  0.458330;0.613250;,
  0.475000;0.613250;,
  0.491670;0.613250;,
  0.508330;0.613250;,
  0.525000;0.613250;,
  0.541670;0.613250;,
  0.558330;0.613250;,
  0.575000;0.613250;,
  0.591670;0.613250;,
  0.608330;0.613250;,
  0.625000;0.613250;,
  0.375000;0.688440;,
  0.391670;0.688440;,
  0.408330;0.688440;,
  0.425000;0.688440;,
  0.441670;0.688440;,
  0.458330;0.688440;,
  0.475000;0.688440;,
  0.491670;0.688440;,
  0.508330;0.688440;,
  0.525000;0.688440;,
  0.541670;0.688440;,
  0.558330;0.688440;,
  0.575000;0.688440;,
  0.591670;0.688440;,
  0.608330;0.688440;,
  0.625000;0.688440;,
  0.604550;0.040130;,
  0.500000;0.150000;,
  0.642740;0.092700;,
  0.548280;0.007650;,
  0.483670;0.000860;,
  0.421880;0.020930;,
  0.373590;0.064410;,
  0.347160;0.123760;,
  0.347160;0.188740;,
  0.373590;0.248090;,
  0.421880;0.291570;,
  0.483670;0.311640;,
  0.548280;0.304850;,
  0.604550;0.272370;,
  0.642740;0.219800;,
  0.656250;0.156250;,
  0.642740;0.907300;,
  0.500000;0.837500;,
  0.604550;0.959870;,
  0.548280;0.992350;,
  0.483670;0.999140;,
  0.421880;0.979070;,
  0.373590;0.935590;,
  0.347160;0.876240;,
  0.347160;0.811260;,
  0.373590;0.751910;,
  0.421880;0.708430;,
  0.483670;0.688360;,
  0.548280;0.695150;,
  0.604550;0.727630;,
  0.642740;0.780200;,
  0.656250;0.843750;,
  0.642740;0.907300;,
  0.642740;0.907300;,
  0.604550;0.959870;,
  0.604550;0.959870;,
  0.548280;0.992350;,
  0.548280;0.992350;,
  0.483670;0.999140;,
  0.483670;0.999140;,
  0.421880;0.979070;,
  0.421880;0.979070;,
  0.373590;0.935590;,
  0.373590;0.935590;,
  0.347160;0.876240;,
  0.347160;0.876240;,
  0.347160;0.811260;,
  0.347160;0.811260;,
  0.373590;0.751910;,
  0.373590;0.751910;,
  0.421880;0.708430;,
  0.421880;0.708430;,
  0.483670;0.688360;,
  0.483670;0.688360;,
  0.548280;0.695150;,
  0.548280;0.695150;,
  0.604550;0.727630;,
  0.604550;0.727630;,
  0.642740;0.780200;,
  0.642740;0.780200;,
  0.656250;0.843750;,
  0.656250;0.843750;,
  0.375000;0.312500;,
  0.375000;0.688440;,
  0.392860;0.688440;,
  0.392860;0.312500;,
  0.410710;0.688440;,
  0.410710;0.312500;,
  0.428570;0.688440;,
  0.428570;0.312500;,
  0.446430;0.688440;,
  0.446430;0.312500;,
  0.464290;0.688440;,
  0.464290;0.312500;,
  0.482140;0.688440;,
  0.482140;0.312500;,
  0.500000;0.688440;,
  0.500000;0.312500;,
  0.517860;0.688440;,
  0.517860;0.312500;,
  0.535710;0.688440;,
  0.535710;0.312500;,
  0.553570;0.688440;,
  0.553570;0.312500;,
  0.571430;0.688440;,
  0.571430;0.312500;,
  0.589290;0.688440;,
  0.589290;0.312500;,
  0.607140;0.688440;,
  0.607140;0.312500;,
  0.625000;0.688440;,
  0.625000;0.312500;,
  0.597420;0.034090;,
  0.500000;0.150000;,
  0.640780;0.088460;,
  0.534770;0.003920;,
  0.465230;0.003920;,
  0.402580;0.034090;,
  0.359220;0.088460;,
  0.343750;0.156250;,
  0.359220;0.224040;,
  0.402580;0.278410;,
  0.465230;0.308580;,
  0.534770;0.308580;,
  0.597420;0.278410;,
  0.640780;0.224040;,
  0.656250;0.156250;,
  0.640780;0.911540;,
  0.500000;0.837500;,
  0.597420;0.965910;,
  0.534770;0.996080;,
  0.465230;0.996080;,
  0.402580;0.965910;,
  0.359220;0.911540;,
  0.343750;0.843750;,
  0.359220;0.775960;,
  0.402580;0.721590;,
  0.465230;0.691420;,
  0.534770;0.691420;,
  0.597420;0.721590;,
  0.640780;0.775960;,
  0.656250;0.843750;;
 }
}
