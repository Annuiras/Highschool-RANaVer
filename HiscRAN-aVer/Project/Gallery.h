#pragma once
class Gallery
{
private:
	//�ŏI�e�p�̃e�N�X�`��(�Z�߂�)
	CTexture	m_BackTexture;

	//�I�����̎l�p�`
	CTexture	m_SelectTexture;

	//�ŏI�e�p�̑䎆�e�N�X�`���i�o���j
	CTexture	m_LastApp[15];

	//�t�H���g�ǂݍ���
	CFont		gFont1;
	CFont		gFont2;

	//�ŏI�e�p�̑䎆�e�N�X�`���i�o���j���W�i�[
	Vector2		pos[15] =
	{
		{60,60},
		{180,60},
		{300,60},
		{420,60},
		{540,60},
		{60,260},
		{180,260},
		{300,260},
		{420,260},
		{540,260},
		{60,460},
		{180,460},
		{300,460},
		{420,460},
		{540,460}
	};

	//�ŏI�e�p�̑䎆�e�N�X�`���i�s�b�N�A�b�v�p�j
	CTexture	m_LastAppPic[15];

	CTexture	m_PickUp;
	CTexture	m_Text;

	bool LastAddFlag[15] =
	{
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
	};

public:
	Gallery();
	~Gallery();
	void Initialize(void);
	void Update(void);
	void Render(void);
	bool Load(void);
	void Release(void);

};

