#pragma once

#include	"Mof.h"
#include "Define.h"

//エフェクト種類列挙
enum tag_EFFECTTYPE {
	EFC_GET_DP,						//DP取得
	//EFC_EXPLOSION01,				//敵爆破
	//EFC_EXPLOSION02,				//プレイヤー爆破

	EFC_TYPE_COUNT,
};


class CEffect
{	
private:
	CTexture* m_pTexture;
	CSpriteMotionController	m_Motion;
	float					m_PosX;
	float					m_PosY;
	bool					m_bShow;
	CRectangle				m_SrcRect;
public:
	CEffect();
	~CEffect();
	void Initialize(int type);
	void Start(float px, float py);
	void Update(CRectangle plrec);
	void Render(void);
	//デバッグ表示
	void RenderDebugging(void);

	void Release(void);

	//テクスチャのポインタを受け取る
	void SetTexture(CTexture* pt) { m_pTexture = pt; }

	//プレイヤー矩形取得
	CRectangle GetRect(void);

	//表示中か判定 true=表示中
	bool GetShow(void) { return m_bShow; }
	
};

