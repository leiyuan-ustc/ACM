//Dancing Links 精确覆盖问题
//矩阵mtx中选取若干行覆盖所有的列，每列有且仅有一个1
//Line[i]表示i所在行，Col[i]表示i所在列
//建图时列头结点编号1-maxcol，其他点依次编号
//resume操作时顺序应与remove顺序相反

void build()
{
    memset(mtx,0,sizeof(mtx));

    //建立矩阵mtx
    
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    memset(U,0,sizeof(U));
    memset(D,0,sizeof(D));
    memset(S,0,sizeof(S));
    
    tot=maxcol;
    for (int i=1;i<=maxline;i++)
        for (int j=1;j<=maxcol;j++)
            if (mtx[i][j]==1)
            {
                tot++;
                mtx[i][j]=tot;
                Col[tot]=j;
                Line[tot]=i;
                S[j]++;
            }
    
    for (int i=0;i<=maxcol;i++)
    {
        R[i]=i+1;
        L[i]=i-1;
    }
    L[0]=maxcol; R[maxcol]=0;
    
    int head,pre;
    for (int i=1;i<=maxline;i++)
    {
        head=pre=0;
        for (int j=1;j<=maxcol;j++)
            if (mtx[i][j]!=0)
            {
                if (head==0) head=mtx[i][j];
                else
                {
                    R[pre]=mtx[i][j];
                    L[mtx[i][j]]=pre;
                }
                pre=mtx[i][j];
            }
        if (head==0) continue;
        
        L[head]=pre;
        R[pre]=head;
    }
    
    for (int i=1;i<=maxcol;i++)
    {
        head=i;
        pre=i;
        for (int j=1;j<=maxline;j++)
            if (mtx[j][i]!=0)
            {
                U[mtx[j][i]]=pre;
                D[pre]=mtx[j][i];
                pre=mtx[j][i];
            }
        D[pre]=i;
        U[i]=pre;
    }
    
    //用remove直接删掉一些已经取过的点
}

void remove(int c)
{
    L[R[c]]=L[c];
    R[L[c]]=R[c];
    
    for (int i=D[c];i!=c;i=D[i])
    {
        for (int j=R[i];j!=i;j=R[j])
        {
            U[D[j]]=U[j];
            D[U[j]]=D[j];
            S[Col[j]]--;
        }
    }
}

void resume(int c)
{
    for (int i=U[c];i!=c;i=U[i])
        for (int j=L[i];j!=i;j=L[j])
        {
            U[D[j]]=j;
            D[U[j]]=j;
            S[Col[j]]++;
        }
    
    L[R[c]]=c;
    R[L[c]]=c;
}

bool dfs()//找到一个解，不一定是最优解
{
    if (R[0]==0) return 1;
    
    int idx=R[0];
    for (int i=R[0];i!=0;i=R[i])
        if (S[i]<S[idx]) idx=i;
    
    remove(idx);
    
    for (int i=D[idx];i!=idx;i=D[i])
    {   
        //记录答案
        for (int j=R[i];j!=i;j=R[j])
            remove(Col[j]);
        if (dfs()) return 1;
        for (int j=L[i];j!=i;j=L[j])
            resume(Col[j]);
    }
    
    resume(idx);
    return 0;
}

//重复覆盖问题对remove，resume，dfs进行修改
void dfs(int x)
{
	if (x>=ans) return;
	if (R[0]==0) 
	{
		ans=x;
		return;
	}
	
	int idx=R[0];
	
	for (int i=D[idx];i!=idx;i=D[i])
	{
		remove(i);
		for (int j=R[i];j!=i;j=R[j])
			remove(j);
		dfs(x+1);
		for (int j=L[i];j!=i;j=L[j])
			resume(j);
		resume(i);
	}
	

	return;
}

void remove(int c)
{
    for (int i=D[c];i!=c;i=D[i])
    {
        L[R[i]]=L[i];
        R[L[i]]=R[i];
    }
}

void resume(int c)
{
    for (int i=U[c];i!=c;i=U[i])
    {
        L[R[i]]=i;
        R[L[i]]=i;
    }
}
