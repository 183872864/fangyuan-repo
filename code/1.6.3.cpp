#pragma once

#include<tuple>
#include<vector>
#include "GameEntry.h"

using namespace std;
class CGame;

class CGameMenuPanel : public CGameEntryMoveable
{
    public:
    CGameMenuPanel();
    ~CGameMenuPanel();


    //存放一个CGame指针在本中
    void SetParent(CGmae* g)
    {
        m_pParent = g;
    };
    CGame *m_pParent{nullptr};  //存放一个CGame指针在本中

    virtual void Draw(Graphics &gh) const;   //画自己
    
    RectF m_rect{0，0，800，600};      //自己的范围

    void OnMouseMove(UINT nFlags,CPiont point);  //处理鼠标移动事件

    void OnLButtonUp(UINT nFlags,CPiont point);   //处理鼠标左键抬起事件

    Image *m_imgBackground;          //背景图

    struct {
        vector<tuple<Image *,RectF>> vImgInfoPtr;
        int index;
    } m_menuItems[2];

}