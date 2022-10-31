#pragma once
#include "Mof.h"

//��
#define BAR_BIG_WIDTH	800
#define BAR_BIG_HEIGHT	40

//��
#define BAR_MEDIUM_WIDTH	500
#define BAR_MEDIUM_HEIGHT	25

//��
#define BAR_SMALL_WIDTH		300
#define BAR_SMALL_HEIGHT	5


#define BAR_VOLUME	5


class Bar
{
private:


	//���W
	float b_PosX;
	float b_PosY;

	//����^�C�v�ʉ���
	float b_HitWidth;

	//�\���t���O:true�F�\��
	bool b_Show;

	//�����ށi���j
	//1:��
	//2:��
	//3:��
	int b_Type;



public:

	Bar();
	~Bar();



	void Render(void);
	void Initialize(void);
	void Start(float posy,int type);
	void Update(float over);

	CRectangle GetRect(int type);


	float GetY(void) { return b_PosY; }

	bool Getshow(void) { return b_Show; }

	//����̎�ނ��擾
	int Gettype(void) { return b_Type; }


};

