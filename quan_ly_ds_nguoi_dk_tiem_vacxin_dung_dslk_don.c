
#include <string.h>
#include <stdio.h>
using namespace std;
//tao cau truc ds
struct ds_nguoi_dk_tiem
{
    int so_CCCD;
    char ho_ten[150];
    int tuoi;
    char nghe_nghiep[200];
};
//tao cau truc danh sach lien ket don
struct Node
{       ds_nguoi_dk_tiem *data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
};
//khoi tao danh sach lien ket don
void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}
//nhap thong tin nguoi dk
ds_nguoi_dk_tiem *Nhaptt()
{
    ds_nguoi_dk_tiem *ds=new ds_nguoi_dk_tiem;

    scanf("%d",&ds->so_CCCD);
    

    gets(ds->ho_ten);
     scanf("%d",&ds->tuoi);
    gets(ds->nghe_nghiep);
    return ds;
}
//tao node danh sach
Node *CreateNode( *ds)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=ds;
        pNode->pNext=NULL;
    }
    else
    {
        pritnf("cap phat bo nho that bai");
    }
    return pNode;
}
//them node vao cuoi danh sach
void InsertLast(SingleList *&list,ds_nguoi_dk_tiem *ds)
{
    Node *pNode=CreateNode(ds);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
         
        while(pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
}
//hien thi danh sach
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        printf("Danh sach rong");
        return;
    }
printf("        DANH SACH DANG KY TIEM VACXIN COVID     ");
printf("STT     So CCCD     Ho ten          Tuoi    Nghe nghiep");
    while(pTmp!=NULL)
    {  
        ds_nguoi_dk_tiem *ds=pTmp->data;
       printf("%d",ds->so_CCCD);
        printf("%c",ds->ho_ten)
        printf("%d",ds->Tuoi);
        printf("%c",ds->nghe_nghiep);
        
       pTmp=pTmp->pNext;
    }
}
//chen
void ChenDau(SingleList &ds, NODE *p) {

    if (ds.pHead==NULL){
       
        ds.pHead = p;
        ds.pTail = p;
    }
  
    else {
       
        p->next = ds.pHead;
      
        ds.pHead = p;
    }
}
void ChenCuoi (SingleList &ds, NODE *p){
  
    if (ds.pHead==NULL) {
     
        ds.pHead=p;
        ds.pTail=p;
    }
    
    else {
       
        ds.pTail->next=p;
        
        ds.pTail=p;
    }
}
void ChenGiua(SingleList &ds, NODE *q, NODE *p){
  
    if (q!=NULL){
       
        p->next=q->next;
        
        q->next=p;
       
        if (q==ds.pTail){
            ds.pTail=p;
        }
    }
    
    else{
        
        ChenDau(ds, p);
    }
}
int main(int argc, char** argv) {
    printf("Chon chuc nang");
    //printf()

    SingleList *list;
    Initialize(list);
    SinhVien *teo=NhapSinhVien();
    InsertLast(list,teo);
    SinhVien *ty=NhapSinhVien();
    InsertLast(list,ty);
    SinhVien *bin=NhapSinhVien();
    InsertLast(list,bin);
    PrintList(list);
    SortList(list);
    cout<<"\nSau khi sap xep:\n";
    PrintList(list);
    cout<<"\Ban muon xoa sinh vien co MSSV: ";
    int ma;
    cin>>ma;
    RemoveNode(list,ma);
    cout<<"\nSau khi xoa:\n";
    PrintList(list);
 
  
}