//十字链表

#include <string>
using namespace std;
typedef string InfoType;
typedef string VertexType;

typedef struct VexNode
{
    VertexType data;  // 顶点的数据域
    ArcBox *firstIn;  // 指向该顶点的第一条入弧
    ArcBox *firstOut; // 指向该顶点的第一条出弧
} VexNode;

typedef struct ArcBox
{
    int tailVex;          // 该弧的尾顶点的位置
    int headVex;          // 该弧的头顶点的位置
    struct ArcBox *hLink; // 弧头相同的弧的链域
    static ArcBox *tLink; // 弧尾相同的弧的链域
    InfoType info;        // 弧的相关信息
} ArcBox;

#define MAX_VERTEX_BUM 20
typedef struct
{
    VexNode xList[MAX_VERTEX_BUM]; // 表头向量
    int vexNum;                    // 图的顶点个数
    int arcNum;                    // 图的边数
} OLGraph;