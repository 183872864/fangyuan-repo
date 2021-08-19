void CMainFrame::OnMouseMove(UINT nFlags, CPoint point)
{
    m_game.OnMouseMove(nFlags, point); //直接把鼠标消息转给CGame对象
    CFrameWnd::OnMouseMove(nflags, point);
}

void CMainFrame::OnLButtonUp(UINT nFlags, CPoint point)
{
   m_game.OnLButtonUp(nFlags, point);  //直接把鼠标消息转给CGame对象
   CFrameWnd::OnLButtonUp(nFlags, point);
}