

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <cstring>
#include "cmd_console_tools.h"
#include "cmd_hdc_tools.h"
#include "hanoi.h"
#include "hanoi_const_value.h"
using namespace std;

static int step = 0;
static int A[10];
static int topa = 0;
static int B[10];
static int topb = 0;
static int C[10];
static int topc = 0;
static int t = 0;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：MenuItem_Start_X
  功    能：根据参数调整 MenuItem_Start_X
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int MenuItem_Start_X(char slt)
{
    if (slt == '4')
        return MenuItem4_Start_X;
    else if (slt == '8')
        return MenuItem8_Start_X;
    else if (slt == '9')
        return MenuItem9_Start_X;
    else
        return 0;
}

/***************************************************************************
  函数名称：MenuItem_Start_Y
  功    能：根据参数调整 MenuItem_Start_Y
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int MenuItem_Start_Y(char slt)
{
    if (slt == '4')
        return MenuItem4_Start_Y;
    else if (slt == '8')
        return MenuItem8_Start_Y;
    else if (slt == '9')
        return MenuItem9_Start_Y;
    else
        return 0;
}

/***************************************************************************
  函数名称：input
  功    能：输入函数(1-8,9的部分)
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input(int* n, char* src, char* dst, int* t, char slt)
{
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> *n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(20000, '\n');
            continue;
        }
        else {
            if (*n >= 1 && *n <= MAX_LAYER) {
                cin.ignore(20000, '\n');
                break;
            }
            else {
                cin.ignore(20000, '\n');
                continue;
            }
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> *src;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(20000, '\n');
            continue;
        }
        else {
            if (*src == 'A' || *src == 'B' || *src == 'C') {
                cin.ignore(20000, '\n');
                break;
            }
            else if (*src == 'a' || *src == 'b' || *src == 'c') {
                *src -= 32;
                cin.ignore(20000, '\n');
                break;
            }
            else {
                cin.ignore(20000, '\n');
                continue;
            }
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> *dst;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(20000, '\n');
            continue;
        }
        else {
            if (*dst == 'A' || *dst == 'B' || *dst == 'C') {
                if (*dst == *src) {
                    cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
                    cin.ignore(20000, '\n');
                    continue;
                }
                else {
                    cin.ignore(20000, '\n');
                    break;
                }
            }
            else if (*dst == 'a' || *dst == 'b' || *dst == 'c') {
                *dst -= 32;
                if (*dst == *src) {
                    cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
                    cin.ignore(20000, '\n');
                    continue;
                }
                else {
                    cin.ignore(20000, '\n');
                    break;
                }
            }
            else {
                cin.ignore(20000, '\n');
                continue;
            }
        }
    }
    if (slt == '4' || slt == '7' || slt == '8'||slt=='9') {
        while (1) {
            if (slt == '4')
                cout << "请输入移动速度(0-200：0-按回车单步演示 1-200:延时1-200ms)";
            else
                cout << "请输入移动速度(0-20：0-按回车单步演示 1-20:延时1-20ms)";

            cout << endl;
            cin >> *t;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(20000, '\n');
                continue;
            }
            else {
                if (slt == '7' || slt == '8'||slt=='9') {
                    if (*t >= 0 && *t <= 20) {
                        cin.ignore(20000, '\n');
                        break;
                    }
                    else {
                        cin.ignore(20000, '\n');
                        continue;
                    }
                }
                if (slt == '4') {
                    if (*t >= 0 && *t <= 200) {
                        cin.ignore(20000, '\n');
                        break;
                    }
                    else {
                        cin.ignore(20000, '\n');
                        continue;
                    }
                }
            }
        }
    }
}

/***************************************************************************
  函数名称：Status_Line
  功    能：状态栏输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Status_Line(char src,char dst,int n,char slt)
{
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "从" << src << "移动到" << dst << "，共" << n << "层";
    if (slt == '4' || slt == '8')
        cout << "，延时设置为" << t << "ms";
    if (slt == '8')
        cout << "（前7步，后面自动变为0ms）";
}

/***************************************************************************
  函数名称：sleep
  功    能：延时
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void sleep(int t) {
    if (t != 0)
        Sleep(t);
    else {
        int ch;
        while (1) {
            ch = _getch();
            if (ch == '\r')
                break;
        }
    }
}

/***************************************************************************
  函数名称：TOP
  功    能：栈与指针操作
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int TOP(char src,char dst)
{
    int mid = 0;
    if (src == 'A')
        mid = A[--topa];
    if (src == 'B')
        mid = B[--topb];
    if (src == 'C')
        mid = C[--topc];
    if (dst == 'A')
        A[topa++] = mid;
    if (dst == 'B')
        B[topb++] = mid;
    if (dst == 'C')
        C[topc++] = mid;
    return mid;
}

/***************************************************************************
  函数名称：TOP0
  功    能：栈与指针操作（初始）
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void TOP0(char src, char dst ,int n)
{
    int i;
    if (src == 'A') {
        for (i = 0; i < n; i++) {
            A[i] = n - i;
        }
        topa = n;
    }
    if (src == 'B') {
        for (i = 0; i < n; i++) {
            B[i] = n - i;
        }
        topb = n;
    }
    if (src == 'C') {
        for (i = 0; i < n; i++) {
            C[i] = n - i;
        }
        topc = n;
    }
}

/***************************************************************************
  函数名称：temple3
  功    能：画三个圆柱
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void temple3() {
    hdc_init();
    hdc_cls();

    hdc_rectangle(HDC_Start_X, HDC_Start_Y, HDC_Base_Width * 23, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width + HDC_Underpan_Distance, HDC_Start_Y, HDC_Base_Width * 23, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 46 * HDC_Base_Width + HDC_Underpan_Distance*2 , HDC_Start_Y, HDC_Base_Width * 23, HDC_Base_High, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 11 * HDC_Base_Width, HDC_Start_Y - 12 * HDC_Base_High, HDC_Base_Width, HDC_Base_High*12, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 34 * HDC_Base_Width + HDC_Underpan_Distance, HDC_Start_Y - 12 * HDC_Base_High, HDC_Base_Width, HDC_Base_High * 12, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(HDC_Start_X + 57 * HDC_Base_Width + HDC_Underpan_Distance*2, HDC_Start_Y - 12 * HDC_Base_High, HDC_Base_Width, HDC_Base_High * 12, HDC_COLOR[11]);
}

/***************************************************************************
  函数名称：dr_plate
  功    能：画盘子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void dr_plate(int n, char src, char tmp, char dst)
{
    for (int i = n; i > 0; i--) {
        hdc_rectangle(HDC_Start_X + (11 - i + 23 * (src - 65)) * HDC_Base_Width + HDC_Underpan_Distance * (src - 65), HDC_Start_Y - HDC_Base_High * (n - i + 1), HDC_Base_Width * (2 * i + 1), HDC_Base_High, HDC_COLOR[i]);
        Sleep(HDC_Init_Delay);
    }
}

/***************************************************************************
  函数名称：mv_plate
  功    能：移动盘子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mv_plate(int n, int t, char src, char tmp, char dst, char slt,int mid)
{
    tmp = 'A' + 'B' + 'C' - src - dst;

    int srcIdx = src - 'A';
    int dstIdx = dst - 'A';

    int x, y;
    int w;
    int dstX, dstY;
    int stepX;
    int plate_cnt[3];
    plate_cnt[0] = topa;
    plate_cnt[1] = topb;
    plate_cnt[2] = topc;


    //初始位置坐标
    w = (2 * mid + 1) * HDC_Base_Width;
    
    x = HDC_Start_X + (11 - mid + 23 * srcIdx) * HDC_Base_Width + HDC_Underpan_Distance * srcIdx;

    if (slt == '8'||slt=='9')
        y = HDC_Start_Y - HDC_Base_High * (plate_cnt[srcIdx] + 1);
    else
        y = HDC_Start_Y - HDC_Base_High * n;

    //向上移动
    if (step <= 7 || slt == '9' || slt == '7')
        sleep(t);
    else
        Sleep(0);
    while (y > HDC_Top_Y){
        hdc_rectangle(x, y + HDC_Base_High - HDC_Step_Y, w, HDC_Step_Y, HDC_COLOR[0]);
        if (y > HDC_Start_Y - 13 * HDC_Base_High)
            hdc_rectangle(x + (w - HDC_Base_Width) / 2,y + HDC_Base_High - HDC_Step_Y,HDC_Base_Width,HDC_Step_Y,HDC_COLOR[11]);
        hdc_rectangle(x, y - HDC_Step_Y,w, HDC_Step_Y, HDC_COLOR[mid]);
        
        y -= HDC_Step_Y;
        
        if (step <= 7||slt=='9' || slt == '7')
            sleep(t);
        else
            Sleep(0);
    }

    //水平移动
    dstX = HDC_Start_X+ (11 - mid + 23 * dstIdx) * HDC_Base_Width+ HDC_Underpan_Distance * dstIdx;
    
    if (dstX > x)
        stepX = HDC_Step_X;
    else
        stepX = -HDC_Step_X;

    while (x != dstX){
        if (stepX > 0){
            hdc_rectangle(x, y, HDC_Step_X, HDC_Base_High, HDC_COLOR[0]);
            hdc_rectangle(x + w, y, HDC_Step_X, HDC_Base_High, HDC_COLOR[mid]);
        }
        else{
            hdc_rectangle(x + w - HDC_Step_X, y,HDC_Step_X, HDC_Base_High,HDC_COLOR[0]);
            hdc_rectangle(x - HDC_Step_X, y,HDC_Step_X, HDC_Base_High,HDC_COLOR[mid]);
        }

        x += stepX;
        if (step <= 7 || slt == '9' || slt == '7')
            sleep(t);
        else
            Sleep(0);
    }

    //向下移动
    if (slt == '8' || slt == '9')
        dstY = HDC_Start_Y - HDC_Base_High * (plate_cnt[dstIdx]);
    else
        dstY = HDC_Start_Y - HDC_Base_High;
    while (y < dstY){
        hdc_rectangle(x, y, w, HDC_Step_Y, HDC_COLOR[0]);
        if (y > HDC_Start_Y - 12 * HDC_Base_High)
            hdc_rectangle(x + (w - HDC_Base_Width) / 2,y,HDC_Base_Width,HDC_Step_Y,HDC_COLOR[11]);
        hdc_rectangle(x, y + HDC_Base_High,w, HDC_Step_Y,HDC_COLOR[mid]);
        y += HDC_Step_Y;
        if (step <= 7 || slt == '9' || slt == '7')
            sleep(t);
        else
            Sleep(0);
    }

    plate_cnt[srcIdx]--;
    plate_cnt[dstIdx]++;
}

/***************************************************************************
  函数名称：platez
  功    能：纵向数组打印
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void platez(char slt)
{
    int i;
    for (i = 0; i < topa || i < topb || i < topc; i++) {
        cct_gotoxy(MenuItem_Start_X(slt) + Underpan_A_X_OFFSET-1, MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 2 - i);
        if (i < topa)
            cout << setw(2) <<  A[i] ;//N=10
        else
            cout << "  ";
        if (i < topb)
            cout << setw(Underpan_Distance) << B[i];
        else {
            for (int j = 0; j < Underpan_Distance; j++)
                cout << " ";
        }
        if (i < topc)
            cout << setw(Underpan_Distance) << C[i];
        else {
            for (int j = 1; j < Underpan_Distance; j++)
                cout << " ";
        }
    }
    cct_gotoxy(MenuItem_Start_X(slt) + Underpan_A_X_OFFSET - 2, MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 1);
    cout << "==";
    for (i = 0; i < 2 * Underpan_Distance; i++)
        cout << "=";
    cout << "==";
    cct_gotoxy(MenuItem_Start_X(slt) + Underpan_A_X_OFFSET, MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET);
    cout << "A";
    for (i = 1; i < Underpan_Distance; i++)
        cout << " ";
    cout << "B";
    for (i = 1; i < Underpan_Distance; i++)
        cout << " ";
    cout << "C";
}

/***************************************************************************
  函数名称：plateh
  功    能：横向数组打印
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void plateh()
{
    int i;
    cout << "A:";
    for (i = 0; i < topa; i++)
        cout << setw(2) << A[i];
    for (i = 0; i < 21 - 2 * topa; i++)
        cout << ' ';
    cout << "B:";
    for (i = 0; i < topb; i++)
        cout << setw(2) << B[i];
    for (i = 0; i < 21 - 2 * topb; i++)
        cout << ' ';
    cout << "C:";
    for (i = 0; i < topc; i++)
        cout << setw(2) << C[i];
    for (i = 0; i < 21 - 2 * topc; i++)
        cout << ' ';
}

/***************************************************************************
  函数名称：cctmove
  功    能：光标移动空格抹去
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void cctmove(char src,char dst,char slt)
{
    platez(slt);
    if (src == 'A') {
        cct_gotoxy((src - 65) * Underpan_Distance+(MenuItem_Start_X(slt) + Underpan_A_X_OFFSET), MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 2 - topa);
        cout << ' ';
    }
    if (src == 'B') {
        cct_gotoxy((src - 65) * Underpan_Distance + (MenuItem_Start_X(slt) + Underpan_A_X_OFFSET), MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 2 - topb);
        cout << ' ';
    }
    if (src == 'C') {
        cct_gotoxy((src - 65) * Underpan_Distance + (MenuItem_Start_X(slt) + Underpan_A_X_OFFSET), MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 2 - topc);
        cout << ' ';
    }
    if (dst == 'A')
        cct_gotoxy((dst - 65) * Underpan_Distance + (MenuItem_Start_X(slt) + Underpan_A_X_OFFSET)+1, MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 1 - topa);
    if (dst == 'B')
        cct_gotoxy((dst - 65) * Underpan_Distance + (MenuItem_Start_X(slt) + Underpan_A_X_OFFSET)+1, MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 1 - topb);
    if (dst == 'C')
        cct_gotoxy((dst - 65) * Underpan_Distance + (MenuItem_Start_X(slt) + Underpan_A_X_OFFSET)+1, MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 1 - topc);
    if (step <= 7 || slt == '9' || slt == '4')
        sleep(t);
    else
        Sleep(0);
}

/***************************************************************************
  函数名称：H0
  功    能：4和8的初始状态
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void H0(char src,int n,char slt)
{
    cct_gotoxy(MenuItem_Start_X(slt), MenuItem_Start_Y(slt));
    cout << "初始:  ";
    plateh();
    cct_gotoxy(MenuItem_Start_X(slt) - Underpan_A_X_OFFSET, MenuItem_Start_Y(slt) - Underpan_A_Y_OFFSET);
    platez(slt);
    cct_gotoxy((src - 65) * Underpan_Distance + (MenuItem_Start_X(slt) + Underpan_A_X_OFFSET)+1, MenuItem_Start_Y(slt) + Underpan_A_Y_OFFSET - 1 - n);
    if (slt == '4')
        sleep(t);
}

/***************************************************************************
  函数名称：Hanoi
  功    能：递归函数调用的函数（合集）
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Hanoi(int n, char src, char tmp, char dst, char slt) {
    int mid = TOP(src, dst);                       //确定盘号
    step += 1;
    if (slt == '4' || slt == '8')
        cct_gotoxy(MenuItem_Start_X(slt), MenuItem_Start_Y(slt));
    if (slt != '7' && slt != '1')
        cout << "第" << setw(4) << step << " 步( ";
    if (slt != '7')
        cout << mid << "#: " << src << "-->" << dst << ' ';
    if (slt == '4' || slt == '3' || slt == '8') {
        plateh();
        if (slt == '4' || slt == '8')
            cctmove(src, dst, slt);
    }
    if (slt == '1' || slt == '2' || slt == '3') {
        cout << endl;
    }
    if (slt == '8')
        mv_plate(n, t, src, tmp, dst, slt, mid);
}

/***************************************************************************
  函数名称：hanoi
  功    能：递归函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, char slt)
{
    if (n == 0)                                        //递归终止
        return;
    else {
        tmp = 'A' + 'B' + 'C' - src - dst;           //确定中间柱
        hanoi(n - 1, src, dst, tmp, slt);
        Hanoi(n, src, tmp, dst, slt);
        hanoi(n - 1, tmp, src, dst, slt);
    }
}

/***************************************************************************
  函数名称：SLT9
  功    能：游戏9
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void SLT9(char src,char dst,char tmp,int n,char slt)
{
    tmp = 'A' + 'B' + 'C' - src - dst;
    while (1) {
        cct_gotoxy(Status_Line_X, Status_Line_Y);
        cout << "从" << src << "移动到" << dst << "，共" << n << "层";
        cct_gotoxy(Status_Line_X + 57, Status_Line_Y - 1);
        cct_gotoxy(Status_Line_X, Status_Line_Y - 1);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
        cct_gotoxy(Status_Line_X+59, Status_Line_Y - 1);
        cout << "                    ";
        cct_gotoxy(Status_Line_X + 57, Status_Line_Y - 1);

        char cmd[100] = { 0 };
        for (int i = 0; i < 100; i++) {
            cmd[i] = _getch();
            if (cmd[i] == '\r')
                break;
            else
                cout << cmd[i];
        }
        int len = strlen(cmd)-1;

        if (len == 1 && (cmd[0] == 'Q' || cmd[0] == 'q')) {
            cct_gotoxy(Status_Line_X, Status_Line_Y);
            cout << "游戏中止!!!!!，共" << n << "层";
            break;
        }

        if (len != 2)
            continue;

        char src1 = cmd[0];
        char dst1 = cmd[1];

        if (src1 >= 'a' && src1 <= 'c') 
            src1 -= 32;
        if (dst1 >= 'a' && dst1 <= 'c') 
            dst1 -= 32;

        if (src1 < 'A' || src1 > 'C' || dst1 < 'A' || dst1 > 'C' || src1 == dst1)
            continue;

        char tmp1 = 'A' + 'B' + 'C' - src1 - dst1;
        int mid1 = 0;
        if (dst1 == 'A'&&topa>0)
            mid1 = A[topa-1];
        if (dst1 == 'B' && topb > 0)
            mid1 = B[topb-1];
        if (dst1 == 'C' && topc > 0)
            mid1 = C[topc-1];
        int mid2 = 0;
        if (src1 == 'A' && topa > 0)
            mid2 = A[topa - 1];
        if (src1 == 'B' && topb > 0)
            mid2 = B[topb - 1];
        if (src1 == 'C' && topc > 0)
            mid2 = C[topc - 1];

        if (mid2 == 0) {
            cct_gotoxy(Status_Line_X, Status_Line_Y);
            cout << "                    ";
            cct_gotoxy(Status_Line_X, Status_Line_Y);
            cout << "源柱为空";
            while (1) {
                char ch = _getch();
                if (ch == '\r') 
                    break;
            }
            cct_gotoxy(Status_Line_X, Status_Line_Y);
            cout << "                    ";
            continue;
        }
        if (mid1!=0&&(mid2 > mid1)) {
            cct_gotoxy(Status_Line_X, Status_Line_Y);
            cout << "                        ";
            cct_gotoxy(Status_Line_X, Status_Line_Y);
            cout << "大盘压小盘，非法操作";
            while (1) {
                char ch = _getch(); 
                if (ch == '\r') 
                    break;
            }
            cct_gotoxy(Status_Line_X, Status_Line_Y);
            cout << "                    ";
            continue;
        }
        int mid = TOP(src1, dst1);
        cct_gotoxy(MenuItem_Start_X(slt), MenuItem_Start_Y(slt));
        step += 1;
        cout << "第" << setw(4) << step << " 步(";
        plateh();
        cctmove(src1, dst1, slt);
        mv_plate(n, t, src1, tmp1, dst1, slt, mid);
        if ((dst == 'A'&&topa==n) || (dst == 'B' && topb == n) || (dst == 'C' && topc == n) ) {
            cct_gotoxy(Status_Line_X , Status_Line_Y+1);
            cout << "游戏结束!!!";
            while (1) {
                char ch = _getch();
                if (ch == '\r')
                    break;
            }
            break;
        }
    }
}



/***************************************************************************
  函数名称：multi_solutions
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void multi_solutions(char slt)
{
    step = 0;
    topa = 0;
    topb = 0;
    topc = 0;  //重来一次的清零操作

    int n=0;
    char src = 0;
    char dst = 0;
    char tmp = 'T';
    if (slt != '5' )  //输入
        input(&n, &src, &dst, &t, slt);
    if (slt == '4' || slt == '6'|| slt == '7' || slt == '8' || slt == '9') //状态栏
        Status_Line(src, dst, n, slt);
    if (slt == '5') {  //5完成
        cct_cls();
        cct_gotoxy(Status_Line_X, Status_Line_Y+1);
        temple3();
    }

    TOP0(src, dst, n);                                                         //栈顶指针初始操作
    if (slt == '4' || slt == '8'||slt=='9')                                              //4和8\9的初始一栏
        H0(src, n,slt);

    if (slt == '6' || slt == '7' || slt == '8'||slt=='9') {
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        temple3();
        Sleep(HDC_Init_Delay);
        dr_plate(n, src, tmp, dst);                                           //6完成
        if (slt == '7')
            mv_plate(n, t, src, tmp, dst, slt,1);                               //7完成
        cct_gotoxy(Status_Line_X, Status_Line_Y + 2);
        if (slt == '8')
            sleep(t);
    }
    if (slt == '9')                                                                //9完成
        SLT9(src,dst,tmp,n,slt);


    if (slt == '1' || slt == '2' || slt == '3' || slt == '4' || slt == '8')     
        hanoi(n, src, tmp, dst, slt);                                           //递归函数，1，2，3，4，8完成
    if (slt == '1' || slt == '2' || slt == '3')
        cout << endl;
    if (slt == '4'||slt == '8' || slt == '9')
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    cout << "按回车键继续";
    while (1) {
        if (getchar() == 10)
            break;
    }
}