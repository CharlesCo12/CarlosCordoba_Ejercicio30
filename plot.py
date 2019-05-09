import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import imageio
tiempo = np.arange(0,201)*0.01
def plot_for_offset(i):
    # Data for plotting
    t = np.arange(0,101)*0.01
    s = np.loadtxt('datos.dat')[i,:]

    fig, ax = plt.subplots(figsize=(10,5))
    ax.plot(t, s)
    ax.grid()
    ax.set(xlabel='X', ylabel='U',title=tiempo[i])

    # IMPORTANT ANIMATION CODE HERE
    # Used to keep the limits constant
    ax.set_ylim(-0.05, 0.05)

    # Used to return the plot as an image rray
    fig.canvas.draw()       # draw the canvas, cache the renderer
    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8')
    image  = image.reshape(fig.canvas.get_width_height()[::-1] + (3,))

    return image

kwargs_write = {'fps':10, 'quantizer':'nq'}
imageio.mimsave('./movie.gif', [plot_for_offset(i) for i in range(201)], fps=10)