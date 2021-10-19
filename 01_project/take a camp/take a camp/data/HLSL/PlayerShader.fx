float4x4 WorldViewProj : WORLDVIEWPROJ;
float4x4 World :WORLD;
float3   LightDirection;
float4   DiffuseColor;
float3   Eye;
float4   SpecularColor;
float3   RimColor;
float    RimPower;

struct VS_IN
{
	float3 Position : POSITION;
	float3 Normal   : NORMAL;
	float4 Color    :COLOR;         // �f�B�t���[�Y
	float2 TexCoord :TEXCOORD;     // �e�N�X�`��UV
};

struct VS_OUT
{
	float4 Position : POSITION;
	float3 viewDir : TEXCOORD1;
	float3 normalDir : TEXCOORD2;
	float4 Color    :COLOR;         // �f�B�t���[�Y
	float2 TexCoord :TEXCOORD;     // �e�N�X�`��UV
};

texture Tex;
sampler Sampler = sampler_state {
	Texture = Tex;
	MipFilter = LINEAR;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
};

//////////////////////////////////
/* ���_�V�F�[�_ */
//////////////////////////////////
VS_OUT VS(VS_IN In)
{
	VS_OUT Out;

	// ���[���h���W
	Out.Position = mul(float4(In.Position, 1), WorldViewProj);

	// �@��
	Out.normalDir = mul(In.Normal, (float3x3)World);
	Out.normalDir = normalize(Out.normalDir);

	// ���C�e�B���O����
	float LightPower = dot(Out.normalDir, LightDirection);
	LightPower = max(0, LightPower);
	
	// �J���[�̐ݒ�
	Out.Color = DiffuseColor*LightPower;
	Out.Color.a = 1.0f;

	Out.viewDir = normalize(Eye - mul(World, In.Position).xyz);
	
	// UV
	Out.TexCoord = In.TexCoord;

	return Out;
}

//////////////////////////////////
/* �s�N�Z���V�F�[�_ */
//////////////////////////////////
float4 PS(VS_OUT In) :COLOR
{
	float4 col = In.Color;

	// ����
	float rim = 1.0f - abs(dot(In.viewDir, In.normalDir));
	float3 emission = RimColor * pow(rim, RimPower) * RimPower;
	col.rgb += emission;
	col = float4(col.rgb, DiffuseColor.a);

	return col;
}

//////////////////////////////////
/* �e�N�X�`���s�N�Z���V�F�[�_ */
//////////////////////////////////
float4 PS_TEX(VS_OUT In) :COLOR
{
	float4 col = tex2D(Sampler, In.TexCoord);

	// ����
	float rim = 1.0f - abs(dot(In.viewDir, In.normalDir));
	float3 emission = RimColor * pow(rim, RimPower) * RimPower;
	col.rgb+= emission;
	col = float4(col.rgb, DiffuseColor.a);

	return col;
}

technique Shader
{
	pass P0
	{
		VertexShader = compile vs_3_0 VS();
		PixelShader = compile ps_3_0 PS();
	}

	pass P0
	{
		VertexShader = compile vs_3_0 VS();
		PixelShader = compile ps_3_0 PS_TEX();
	}
}