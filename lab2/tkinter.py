from tkinter import *
from tkinter import messagebox
from random import randint
from math import *

global romb, figure, a, b, k, l, xcentr, ycentr, shtr

a = 70
b = 30
k = b*1.5/a
l = b*4.5
romb = []
figure = []
shtr = []

global n
n=800
xcentr = n/2
ycentr = n/2
print("Вершины ромба: \n\t(0;", l,")\n\t(0;", -l,")")

def function(y, x):
    return (x**2 + y**2 -a*y)**2 - b**2 * (x**2 + y**2)
    
def form_figure():
    step = 2*pi / 1000
    t = 0
    while t <= 2*pi:
        c = cos(t)
        s = sin(t)
        x = a*(c**2) + b*c
        y = a*c*s + b*s
        figure.append([x + xcentr,-y + ycentr])
        t += step

def form_romb():
    step = a/1000
    x = -a*3
    print("\t(", x, ";0)\n\t(", -x,";0)")
    while x <= 0:
        y = k*x + l
        romb.append([x + xcentr,y + ycentr])
        romb.append([-x + xcentr,y + ycentr])
        romb.append([x + xcentr,-y + ycentr])
        romb.append([-x + xcentr,-y + ycentr])
        x += step


def shtrikh():
    amount = 10
    lstep = l*2/(amount+1)
    ln = l - lstep
    kn = -k
    for i in range(amount):
        x = -a*3
        stop = -x
        step = 2*abs(x)/1000
        while x<stop:
            ynew = kn*x + ln
            xnew = x
            if (ynew < k*xnew + l and ynew > k*xnew - l and function(xnew, ynew) > 0 and not (xnew > 0 and xnew < (a - b) and (ynew < (a - b)/2) and ynew > (b - a)/2)):
                shtr.append([xnew + xcentr, ynew + ycentr])
            x += step
        ln -= lstep


def err1():
    messagebox.showerror('Ошибка','Неверный ввод чисел')
    
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

def move():
    dx = rsdx.get()
    dy = rsdy.get()
    dx=dx.strip()
    dy=dy.strip()
    qx=chek(dx)
    qy=chek(dy)
    if qx==1 and qy==1:
        dx=float(dx)
        dy=float(dy)
        if fabs(dx) < 0.5 and fabs(dy) < 0.5:
            messagebox.showerror('Ошибка','Слишком маленькое смещение')
        else:
            copy()
            for dot in figure:
                dot[0] += dx
                dot[1] -= dy
            for dot in romb:
                dot[0] += dx
                dot[1] -= dy
            for dot in shtr:
                dot[0] += dx
                dot[1] -= dy
            
            draw(romb, figure, shtr)
    else:
        err1()
    endx.delete(0,END)
    endy.delete(0,END)
        


def scale():
    kx = rskx.get()
    ky = rsky.get()
    xc = rsxc.get()
    yc = rsyc.get()
    kx=kx.strip()
    ky=ky.strip()
    xc=xc.strip()
    yc=yc.strip()
    qx=chek(kx)
    qy=chek(ky)
    qc1=chek(xc)
    qc2=chek(yc)
    if qx==1 and qy==1 and qc1==1 and qc2==1:
        kx=float(kx)
        ky=float(ky)
        xc=float(xc)
        yc=float(yc)
        xc += xcentr
        yc += ycentr
        copy()
        for dot in figure:
            dot[0] = kx*dot[0] + (1-kx)*xc
            dot[1] = ky*dot[1] + (1-ky)*yc
        for dot in romb:
            dot[0] = kx*dot[0] + (1-kx)*xc
            dot[1] = ky*dot[1] + (1-ky)*yc
        for dot in shtr:
            dot[0] = kx*dot[0] + (1-kx)*xc
            dot[1] = ky*dot[1] + (1-ky)*yc
        draw(romb, figure, shtr)
            
    else:
        err1()
    enkx.delete(0,END)
    enky.delete(0,END)
    enxc.delete(0,END)
    enyc.delete(0,END)


def rotate():
    xc1 = rsxc1.get()
    yc1 = rsyc1.get()
    angle = rsa.get()
    xc1=xc1.strip()
    yc1=yc1.strip()
    angle=angle.strip()
    qx=chek(xc1)
    qy=chek(yc1)
    q=chek(angle)
    if qx==1 and qy==1 and q==1:
        xc1=float(xc1)
        yc1=float(yc1)
        angle = float(angle)
        yc1 *= -1
        xc1 += xcentr
        yc1 += ycentr
        a_rad = angle*pi/180
        c = cos(a_rad)
        s = sin(a_rad)
        copy()
        for dot in figure:
            x = dot[0]
            dot[0] = xc1 + (dot[0]-xc1)*c + (dot[1]-yc1)*s
            dot[1] = yc1 - (x-xc1)*s + (dot[1]-yc1)*c
        for dot in romb:
            x = dot[0]
            dot[0] = xc1 + (dot[0]-xc1)*c + (dot[1]-yc1)*s
            dot[1] = yc1 - (x-xc1)*s + (dot[1]-yc1)*c
        for dot in shtr:
            x = dot[0]
            dot[0] = xc1 + (dot[0]-xc1)*c + (dot[1]-yc1)*s
            dot[1] = yc1 - (x-xc1)*s + (dot[1]-yc1)*c

        draw(romb, figure, shtr)
            
    else:
        err1()
    enkx.delete(0,END)
    enky.delete(0,END)
    enxc.delete(0,END)
    enyc.delete(0,END)
  

def delpoint():
    select = lst.curselection()
    if len(select) == 1:
        xarr.pop(select[0])
        yarr.pop(select[0])
        lst.delete(select[0])


def print_fig(dots):
    for dot in dots:
        canv.create_oval(dot[0],dot[1],dot[0],dot[1],width=1, fill = 'black')

def draw(r, f, s):
    canv.delete(ALL)
    canv.create_line(0,ycentr,n,ycentr,fill='red')#оси
    canv.create_text(n-10, ycentr-10, fill = 'black', text = 'X')
    canv.create_line(xcentr,0,xcentr,n,fill='red')
    canv.create_text(xcentr+10, 10, fill = 'black', text = 'Y')
    
    print_fig(r)
    print_fig(f)
    print_fig(s)

def copy():
    global fprev, sprev, rprev
    fprev = []
    rprev = []
    sprev = []
    for dot in figure:
        fprev.append([dot[0], dot[1]])
    for dot in romb:
        rprev.append([dot[0], dot[1]])
    for dot in shtr:
        sprev.append([dot[0], dot[1]])

def copy_back():
    global figure, romb, shtr
    figure = []
    romb = []
    shtr = []
    for dot in fprev:
        figure.append([dot[0], dot[1]])
    for dot in rprev:
        romb.append([dot[0], dot[1]])
    for dot in sprev:
        shtr.append([dot[0], dot[1]])

def back():
    copy_back()
    draw(rprev, fprev, sprev)
    
root=Tk()
root.title('Точки')
# Labels
lbm=Label(root,text='Перенос')
lbm.grid(row=0,column=0, columnspan = 2)
lbdx=Label(root,text='dx:')
lbdx.grid(row=1,column=0)
lbdy=Label(root,text='dy:')
lbdy.grid(row=1,column=1)

lbr=Label(root,text='Масштабирование')
lbr.grid(row=4,column=0, columnspan = 2)
lbkx=Label(root,text='kx:')
lbkx.grid(row=5,column=0)
lbky=Label(root,text='ky:')
lbky.grid(row=5,column=1)
lbxc=Label(root,text='Xc:')
lbxc.grid(row=7,column=0)
lbyc=Label(root,text='Yc:')
lbyc.grid(row=7,column=1)

lbs=Label(root,text='Поворот')
lbs.grid(row=10,column=0, columnspan = 2)
lbxc1=Label(root,text='Xc:')
lbxc1.grid(row=11,column=0)
lbyc1=Label(root,text='Yc:')
lbyc1.grid(row=11,column=1)
lba=Label(root,text='Угол:')
lba.grid(row=13,column=0)

#Область ввода
rsdx=StringVar()
rsdy=StringVar()
rskx=StringVar()
rsky=StringVar()
rsxc=StringVar()
rsyc=StringVar()
rsxc1=StringVar()
rsyc1=StringVar()
rsa=StringVar()

endx=Entry(root,textvariable=rsdx)
endx.grid(row=2,column=0)
endy=Entry(root,textvariable=rsdy)
endy.grid(row=2,column=1)

enkx=Entry(root,textvariable=rskx)
enkx.grid(row=6,column=0)
enky=Entry(root,textvariable=rsky)
enky.grid(row=6,column=1)
enxc=Entry(root,textvariable=rsxc)
enxc.grid(row=8,column=0)
enyc=Entry(root,textvariable=rsyc)
enyc.grid(row=8,column=1)

enxc1=Entry(root,textvariable=rsxc1)
enxc1.grid(row=12,column=0)
enyc1=Entry(root,textvariable=rsyc1)
enyc1.grid(row=12,column=1)
ena=Entry(root,textvariable=rsa)
ena.grid(row=13,column=1)

#Кнопки
btnm=Button(root,text='Перенести',command=move)
btnm.grid(row=3,column=0, columnspan = 2)
btns=Button(root,text='Масштабировать',command=scale)
btns.grid(row=9,column=0, columnspan = 2)
btnr=Button(root,text='Повернуть',command=rotate)
btnr.grid(row=14,column=0, columnspan = 2)
btnback=Button(root,text='Шаг назад',command=back)
btnback.grid(row=16,column=0, columnspan = 2)

canv=Canvas(root,width=n,height=n,bg='white')
canv.grid(row=0,column=2,rowspan=n,columnspan=n)


form_figure()
form_romb()
shtrikh()
copy()
draw(romb, figure, shtr)


root.mainloop()









