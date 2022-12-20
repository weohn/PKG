import numpy as np
from matplotlib import pyplot as plt
import cv2 as cv
from tkinter import *
from PIL import ImageTk, Image
import warnings

warnings.filterwarnings('ignore')
export_parallel = True
use_graph = True
use_numba = True



class App():
    def __init__(self):
        self.image = cv.imread('2d2ff5c4-c8c9-440e-89fd-95ddfecc7d2f.jpg')
        self.imgray = None
        self.trsh1 = None
        self.trsh2 = None

    def original(self):
        img = Image.fromarray(self.image)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def filt(self):
        self.imgray = cv.cvtColor(cv.pyrMeanShiftFiltering(self.image, 15, 50), cv.COLOR_BGR2GRAY)
        img = Image.fromarray(self.imgray)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def equalization(self):
        self.imgray = cv.cvtColor(cv.pyrMeanShiftFiltering(self.image, 15, 50), cv.COLOR_BGR2GRAY)
        img = Image.fromarray(cv.equalizeHist(self.imgray))
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def histogram(self):
        hist, bins = np.histogram(self.imgray.flatten(), 256, [0, 256])
        plt.hist(self.imgray.flatten(), 256, [0, 256], color='r')
        plt.xlim([0, 256])
        plt.legend(('histogram',), loc='upper left')
        plt.show()

    def histogram_equalization(self):
        b, g, r = cv.split(self.image)
        h_b, bin_b = np.histogram(b.flatten(), 256, [0, 256])
        h_g, bin_g = np.histogram(g.flatten(), 256, [0, 256])
        h_r, bin_r = np.histogram(r.flatten(), 256, [0, 256])
        cdf_b = np.cumsum(h_b)
        cdf_g = np.cumsum(h_g)
        cdf_r = np.cumsum(h_r)
        cdf_m = np.ma.masked_equal(cdf_b, 0)
        cdf_m = (cdf_m - cdf_m.min()) * 255 / (cdf_m.max() - cdf_m.min())
        cdf = np.ma.filled(cdf_m, 0).astype('uint8')
        b = cdf[b]
        cdf_m = np.ma.masked_equal(cdf_g, 0)
        cdf_m = (cdf_m - cdf_m.min()) * 255 / (cdf_m.max() - cdf_m.min())
        cdf = np.ma.filled(cdf_m, 0).astype('uint8')
        g = cdf[g]
        cdf_m = np.ma.masked_equal(cdf_r, 0)
        cdf_m = (cdf_m - cdf_m.min()) * 255 / (cdf_m.max() - cdf_m.min())
        cdf = np.ma.filled(cdf_m, 0).astype('uint8')
        r = cdf[r]
        img = cv.merge((b, g, r))
        equ_b = cv.equalizeHist(b)
        equ_g = cv.equalizeHist(g)
        equ_r = cv.equalizeHist(r)
        equ = cv.merge((equ_b, equ_g, equ_r))
        img = Image.fromarray(equ)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def linear(self):
        self.imgray = cv.cvtColor(cv.pyrMeanShiftFiltering(self.image, 15, 50), cv.COLOR_BGR2GRAY)
        self.trsh1 = cv.adaptiveThreshold(self.imgray, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 11, 2)
        img = Image.fromarray(self.trsh1)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)



class Gui:
    def __init__(self, master):
        self.master = master
        self.master.title("Image Processing")
        self.master.geometry("1440x820")
        self.master.resizable(False, False)
        self.master.configure(background="dark slate gray")

        self.solution = App()

        self.frame = Frame(self.master, bg="blue violet")
        self.frame.pack()

        self.label = Label(self.frame, text="Image Processing", font=("Arial", 20), bg="blue violet")
        self.label.grid(row=0, column=0, columnspan=2, pady=10)

        self.button1 = Button(self.frame, text="Original", font=("Arial", 15), bg="silver", command=self.original)
        self.button1.grid(row=1, column=0, pady=10)

        self.button2 = Button(self.frame, text="Filter", font=("Arial", 15), bg="silver", command=self.filt)
        self.button2.grid(row=2, column=0, pady=10)

        self.button3 = Button(self.frame, text="Equalization", font=("Arial", 15), bg="silver", command=self.equalization)
        self.button3.grid(row=3, column=0, pady=10)

        self.button4 = Button(self.frame, text="Histogram Equalization", font=("Arial", 15), bg="silver", command=self.histogram_equalization)
        self.button4.grid(row=4, column=0, pady=10)

        self.button5 = Button(self.frame, text="Linear", font=("Arial", 15), bg="silver", command=self.linear)
        self.button5.grid(row=5, column=0, pady=10)

        self.button8 = Button(self.frame, text="Exit", font=("Arial", 15), bg="silver", command=self.exit)
        self.button8.grid(row=8, column=0, pady=10)

        self.label1 = Label(self.frame, text="Original Image", font=("Arial", 12), bg="blue violet")
        self.label1.grid(row=10, column=1, pady=10)

        self.label2 = Label(self.frame, text="Processed Image", font=("Arial", 12), bg="blue violet")
        self.label2.grid(row=10, column=0, pady=10)

        self.image1 = self.solution.original()
        self.label3 = Label(self.frame, image=self.image1, bg="blue violet")
        self.label3.grid(row=11, column=0, pady=10)

        self.image2 = self.solution.original()
        self.label4 = Label(self.frame, image=self.image2, bg="blue violet")
        self.label4.grid(row=11, column=1, pady=10)

    def original(self):
        self.image1 = self.solution.original()
        self.label3.configure(image=self.image1)
        self.label3.image = self.image1
        self.label2.configure(text="Original Image")

    def filt(self):
        self.image1 = self.solution.filt()
        self.label3.configure(image=self.image1)
        self.label3.image = self.image1
        self.label2.configure(text="Filter Image")

    def equalization(self):
        self.image1 = self.solution.equalization()
        self.label3.configure(image=self.image1)
        self.label3.image = self.image1
        self.label2.configure(text="Equalization Image")


    def histogram_equalization(self):
        self.image1 = self.solution.histogram_equalization()
        self.label3.configure(image=self.image1)
        self.label3.image = self.image1
        self.label2.configure(text="Histogram Equalization Image")

    def linear(self):
        self.image1 = self.solution.linear()
        self.label3.configure(image=self.image1)
        self.label3.image = self.image1
        self.label2.configure(text="Linear Image")

    def exit(self):
        self.master.destroy()

root = Tk()
Gui(root)
root.mainloop()
