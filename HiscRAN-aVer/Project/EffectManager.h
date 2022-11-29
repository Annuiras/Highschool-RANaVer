#pragma once
#include "Define.h"
#include	"Effect.h"

//エフェクト管理クラス
class CEffectMgmt
{

private:
	//エフェクトクラス
	CEffect		m_Effect[EFC_TYPE_COUNT][EFFECT_MGMT_COUNT];

	//エフェクト画像
	CTexture	m_Texture[EFC_TYPE_COUNT];

public:
	CEffectMgmt();
	~CEffectMgmt();
	//素材ロード
	bool Load(void);

	//初期化命令
	void Initialize(void);
	//画面推移時の初期化命令
	void InitializeIn_middle(void);

	//開始命令
	CEffect* Start(float px, float py, tag_EFFECTTYPE type);

	//更新
	void Update(CRectangle plrec);

	//描画
	void Render(void);
	//デバッグ表示
	void RenderDebugging(void);

	//解放
	void Release(void);
	
};

