#pragma once

#include	"Mof.h"
#include "Define.h"

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

	//初期化
	void Initialize(int type);
	//画面推移時の初期化
	void InitializeIn_middle(void);

	//エフェクト開始
	void Start(float px, float py);

	//更新
	void Update(CRectangle plrec);

	//描画
	void Render(void);
	//デバッグ表示
	void RenderDebugging(void);

	//解放
	void Release(void);

	//テクスチャのポインタを受け取る
	void SetTexture(CTexture* pt) { m_pTexture = pt; }

	//プレイヤー矩形取得
	CRectangle GetRect(void);

	//表示中か判定 true=表示中
	bool GetShow(void) { return m_bShow; }
	
};

