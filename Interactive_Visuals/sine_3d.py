# -*- coding: utf-8 -*-
"""sine 3d.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1Z191Ts3p2Er3sJHZpVs6O7zbs0HK7HqW
"""

# Install the required libraries
!pip install plotly

# Import libraries
import plotly.graph_objects as go
import numpy as np

# Create sample data
t = np.linspace(0, 10, 100)
x = t
y = np.sin(t)
z = np.zeros_like(t)

# Create 3D scatter plot
fig = go.Figure(data=[go.Scatter3d(x=x, y=y, z=z, mode='lines', marker=dict(size=4), line=dict(width=2))])

# Customize the layout
fig.update_layout(title='3D Plot of Sin Curve',
                  scene=dict(xaxis_title='X Axis', yaxis_title='Y Axis', zaxis_title='Z Axis'))

# Show the plot
fig.show()