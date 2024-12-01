import tkinter as tk
import sys

command_line_arg = sys.argv[1] if len(sys.argv) > 1 else sys.exit()

def read_file(filebytes):
    widthheight = []
    colormap = []
    # gets width
    widthheight.append((filebytes[0] << 8) | filebytes[1])
    widthheight.append((filebytes[2] << 8) | filebytes[3])

    for i in range(4,len(filebytes)):
        colormap.append(filebytes[i])

    print(widthheight)
    print(colormap)

    return [widthheight,colormap]


def draw_square(x,y,w,h,r,g,b):
    colore = f"#{r:02x}{g:02x}{b:02x}"
    canvas.create_rectangle(x, y, x+w, y+h, outline='', fill=colore)

    print(f"drawing at {x} {y}, size {w} {h} and color {r} {g} {b}.")

root = tk.Tk()

root.title("open-mother sprite viewer")

root.geometry("900x640")

root.config(bg="black")

canvas = tk.Canvas(root, width=640, height=640, bg="gray")
canvas.pack(expand=True) #centers

with open(sys.argv[1], 'rb') as file:
    file_bytes = file.read()

imagedata = read_file(file_bytes)

# draw_square(0,0,10,10)

position = [0,0]
pixel = 0

for y in range(imagedata[0][1]):
    for x in range(imagedata[0][0]):
        draw_square(
        x*(640/imagedata[0][0]), # x position
        y*(640/imagedata[0][1]), # y position
        
        640/imagedata[0][0], # x size
        640/imagedata[0][1], # y size
        
        imagedata[1][4*pixel], # red
        imagedata[1][(4*pixel)+1], # green
        imagedata[1][(4*pixel)+2]) # blue
        pixel += 1
    print("newline")


root.mainloop()
