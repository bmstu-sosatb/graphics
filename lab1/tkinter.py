from tkinter import *
from tkinter import messagebox
from random import randint

def qsort(b):
    if b==[]:
       return b
    index_opor=randint(0,len(b)-1)
    arrBigger=list(filter((lambda k: k>b[index_opor]),b))
    arrLess=list(map((lambda lol:lol[0]),filter((lambda m : (m[0]<=b[index_opor])&(m[1]!=index_opor)),zip(b,range(0,len(b))))))
    return qsort(arrLess)+[b[index_opor]]+qsort(arrBigger)

xarr=[]
yarr=[]
otstup = 30
n=560
n1=n-2*otstup

def err1():
    messagebox.showerror('Ошибка','Координаты введены неверно, повторите ввод')
    
def chek(x):
    q=0
    m=x.find('-')
    t=x.find('.')
    l=len(x)
    if t!=0:
        if (m==0  and t!=1) or m==-1:
            if t!=-1:
                x1=x[m+1:t]+x[t+1:l]
            else:
                x1=x[m+1:l]
            if x1.isdigit():
                q=1
    return q

def addt():
    tx=rstx.get()
    ty=rsty.get()
    tx=tx.strip()
    ty=ty.strip()
    qx=chek(tx)
    qy=chek(ty)
    if qx==1 and qy==1:
        tx=float(tx)
        ty=float(ty)
        flag = 0
        for i in range(len(xarr)):
            if xarr[i] == tx and yarr[i] == ty:
                messagebox.showerror('Ошибка','Данная точка уже существует')
                flag = 1
        if flag == 0:
            xarr.append(tx)
            yarr.append(ty)
            lst.insert(END,'('+str(tx)+';'+str(ty)+')')
    else:
        err1()
    enx.delete(0,END)
    eny.delete(0,END)

def dlt():
    canv.delete(ALL)
    lst.delete(0,END)
    try:
        lbdiff1.destroy()
        lbdiff2.destroy()
        xarr.clear()
        yarr.clear()
    except:
        xarr.clear()
        yarr.clear()

def delpoint():
    select = lst.curselection()
    if len(select) == 1:
        xarr.pop(select[0])
        yarr.pop(select[0])
        lst.delete(select[0])

def editpoint():
    select = lst.curselection()
    if len(select) == 1:
        x = xarr.pop(select[0])
        y = yarr.pop(select[0])
        lst.delete(select[0])
        enx.insert(0, str(x))
        eny.insert(0, y)

def pointdist(a,b,c,d):
    pd=((a-c)**2+(b-d)**2)**(1/2)
    return pd

## вектор АВ, точка С
def find_height(Ax,Ay,Bx,By,Cx,Cy):
    a = Bx - Ax
    b = By - Ay
    c = -a * Cx - b * Cy
    return [a, b, c]

## ki = [ai, bi, ci]
def cross_lines(k1, k2):
    aa = (k1[0] * k2[1] - k2[0] * k1[1])
    if aa != 0:
        x = (k2[2] * k1[1] - k1[2] * k2[1]) / aa
        y = (k2[0] * k1[2] - k2[2] * k1[0]) / (k1[0] * k2[1] - k2[0] * k1[1])
        return [x, y]
    return [0, 0]

## сумма расстояний до осей
def axis_dest(x, y):
    return abs(x) + abs(y)

def solve():
    global l,idiff,jdiff,kdiff,lbdiff1,lbdiff2
    length=len(xarr)

    if length<3:
        messagebox.showerror('Ошибка','Вы ввели меньше трех точек')
    else:
        a=qsort(xarr)
        b=qsort(yarr)
        if a[0]==a[length-1] and b[0]==b[length-1]:
            messagebox.showerror('Ошибка','Все точки совпадают')
        else:
            x1=x2=xarr[0]
            y1=y2=yarr[0]
            i=1
            while i<length and x1==x2 and y1==y2:
                if xarr[i]!=x1 or yarr[i]!=y1:
                    x2=xarr[i]
                    y2=yarr[i]
                i+=1
            q=0
            for i in range(length):
                if (yarr[i]-y1)*(x2-x1)==(xarr[i]-x1)*(y2-y1):
                    q+=1
            if q==length:
                messagebox.showerror('Ошибка','Все точки лежат на одной прямой')
            else:
                idiff=0
                jdiff=0
                kdiff=0
                heightdest = -1
                height1 = []
                height2 = []
                global point
                point = []
                dest = []
                for i in range(length-2):
                    for j in range(i,length-1):
                        for k in range(j,length):
                            newheight1 = find_height(xarr[i], yarr[i], xarr[j], yarr[j], xarr[k], yarr[k])
                            newheight2 = find_height(xarr[k], yarr[k], xarr[j], yarr[j], xarr[i], yarr[i])
                            newpoint = cross_lines(newheight1, newheight2)
                            dest = axis_dest(newpoint[0], newpoint[1])
                            if (dest > heightdest):
                                idiff = i
                                jdiff = j
                                kdiff = k
                                heightdest = dest
                                height1 = newheight1
                                height2 = newheight2
                                point = newpoint
                draw()
                lbdiff1=Label(root,text='Координаты точки пересечения высот:')
                lbdiff1.grid(row=30,column=0)
                string = '(' + str(point[0]) + ';' + str(point[1]) + ')'
                lbdiff2=Label(root,text=string)
                lbdiff2.grid(row=31,column=0)  
    

def draw():
    canv.delete(ALL)
    xarr.append(0)
    xarr.append(point[0])
    yarr.append(0)
    yarr.append(point[1])
    xmax=max(xarr)
    xmin=min(xarr)
    ymax=max(yarr)
    ymin=min(yarr)
    for i in range(2):
        xarr.pop()
        yarr.pop()
    dx=abs(xmax-xmin)
    dy=abs(ymax-ymin)
    l=len(xarr)
    if dx>dy:
        delta=(n1)/dx
    else:
        delta=(n1)/dy
    for i in range(l):
        x=(xarr[i]-xmin)*delta+otstup
        y=n1-(yarr[i]-ymin)*delta+otstup
        canv.create_oval(x,y,x,y,width=5)
        string = '(' + str(xarr[i]) + ';' + str(yarr[i]) + ')'
        canv.create_text(x, y-7, fill = 'black', text = string)
    
    x=(point[0]-xmin)*delta+otstup
    y=n1-(point[1]-ymin)*delta+otstup
    canv.create_oval(x,y,x,y,width=5,outline = 'blue')
    string = '(' + str(point[0]) + ';' + str(point[1]) + ')'
    canv.create_text(x, y-7, fill = 'black', text = string)
     
    x0=(-xmin)*delta+otstup
    y0=n1-(-ymin)*delta+otstup
    x1=(10000-xmin)*delta+otstup
    y1=n1-(10000-ymin)*delta+otstup
    x2=(-10000-xmin)*delta+otstup
    y2=n1-(-10000-ymin)*delta+otstup
    canv.create_line(x2,y0,x1,y0,fill='yellow')#оси
    canv.create_line(x0,y2,x0,y1,fill='yellow')
    x0=(xarr[idiff]-xmin)*delta+otstup
    y0=n1-(yarr[idiff]-ymin)*delta+otstup
    x1=(xarr[jdiff]-xmin)*delta+otstup
    y1=n1-(yarr[jdiff]-ymin)*delta+otstup
    x2=(xarr[kdiff]-xmin)*delta+otstup
    y2=n1-(yarr[kdiff]-ymin)*delta+otstup
    canv.create_polygon(x0,y0,x1,y1,x2,y2,fill='',outline='red')
root=Tk()
root.title('Точки')
lbx=Label(root,text='Введите координату х')
lbx.grid(row=0,column=0)
lby=Label(root,text='Введите координату у')
lby.grid(row=2,column=0)
#Область ввода
rstx=StringVar()
rsty=StringVar()
enx=Entry(root,textvariable=rstx)
enx.grid(row=1,column=0)
eny=Entry(root,textvariable=rsty)
eny.grid(row=3,column=0)
#Кнопки
btn1=Button(root,text='Добавить точку',command=addt)
btn1.grid(row=4,column=0)
btn2=Button(root,text='Решить',command=solve)
btn2.grid(row=26,column=0)
btn3=Button(root,text='Удалить все',command=dlt)
btn3.grid(row=29,column=0)
btn4=Button(root,text='Удалить точку',command=delpoint)
btn4.grid(row=28,column=0)
btn5=Button(root,text='Редактировать точку',command=editpoint)
btn5.grid(row=27,column=0)
#Область вывода
lst=Listbox(root,height=20,width=25, selectmode = SINGLE)
##scroll = Scrollbar(command=lst.yview)
##scroll.pack(side=LEFT, fill=Y)
##lst.config(yscrollcommand=scroll.set)
lst.grid(row=5,column=0,rowspan=20)
canv=Canvas(root,width=n,height=n,bg='white')
canv.grid(row=0,column=1,rowspan=n,columnspan=n)
root.mainloop()

































































##    
##def solve1():
##    l=len(xarr)
##    if l<3:
##        messagebox.showerror('Ошибка','Вы ввели меньше трех точек')
##    else:
##        xmax=max(xarr)
##        xmin=min(xarr)
##        ymax=max(yarr)
##        ymin=min(yarr)
##        dx=abs(xmax-xmin)
##        dy=abs(ymax-ymin)
##        a=[]              #список кортежей координат вершин квадрата
##        if dx>dy:
##            a.append((xmin,ymin))
##            a.append((xmin,ymin+dx))
##            a.append((xmax,ymin+dx))
##            a.append((xmax,ymin))
##            pdst=[dx]*4
##        else:
##            a.append((xmin,ymin))
##            a.append((xmin,ymax))
##            a.append((xmin+dy,ymax))
##            a.append((xmin+dy,ymin))
##            pdst=[dy]*4   #список минимальных расстояний от вершин до точки
##        idst=[0]*4        #список номеров точек, ближайших к вершинам квадрата
##        for i in range(l):
##            for j in range(4):
##                pd=pointdist(a[j][0],a[j][1],xarr[i],yarr[i])
##                if pd<pdst[j]:
##                    pdst[j]=pd
##                    idst[j]=i
##        difference=l
##        for i in range(4):
##            a=idst[i]
##            b=idst[(i-1)%4]
##            c=idst[(i+1)%4]
##            inside=0
##            outside=0
##            for j in range(l):
##                if j!=a and j!=b and j!=c:
##                    if pointinside(xarr[a],yarr[a],xarr[b],yarr[b],xarr[c],yarr[c],xarr[j],yarr[j])==1:
##                        inside+=1
##                    else:
##                        outside+=1
##            if abs(inside-outside)<difference:
##                difference=abs(inside-outside)
##                idiff=i
##            a=idst[idiff]
##            b=idst[(idiff-1)%4]
##            c=idst[(idiff+1)%4]
##        canv.create_polygon(xarr[a]+500,500-yarr[a],xarr[b]+500,500-yarr[b],xarr[c]+500,500-yarr[c],fill='',outline='red')#
##        lbdiff1=Label(root,text='Разность количеств:')
##        lbdiff1.grid(row=28,column=0)
##        lbdiff2=Label(root,text=str(difference))
##        lbdiff2.grid(row=29,column=0)

