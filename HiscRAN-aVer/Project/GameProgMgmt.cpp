#include "GameProgMgmt.h"

CGameProgMgmt::CGameProgMgmt():
BGM_Volume(0.0f),
SE_Volume(0.0f)
{
}

CGameProgMgmt::~CGameProgMgmt()
{
}

void CGameProgMgmt::Initialize(void)
{
	//èâä˙âπó 
	BGM_Volume = 0.5f;
	SE_Volume = 0.5f;
}

void CGameProgMgmt::SetBGMVolume(float volume)
{
	BGM_Volume = volume;
}

void CGameProgMgmt::SetSEVolume(float volume)
{
	SE_Volume = volume;

}

float CGameProgMgmt::GetBGMVolume(void)
{
	return BGM_Volume;
}

float CGameProgMgmt::GetSEVolume(void)
{
	return SE_Volume;
}

