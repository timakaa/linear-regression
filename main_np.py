import numpy as np
import matplotlib.pyplot as plt

data = [{"x": 1, "y": 1.5}, {"x": 2, "y": 3.8}, {"x": 3, "y": 6.7}, 
        {"x": 4, "y": 9.0}, {"x": 5, "y": 11.2}, {"x": 6, "y": 13.6}, 
        {"x": 7, "y": 16}]

# Extract x and y values
x_values = np.array([point["x"] for point in data])
y_values = np.array([point["y"] for point in data])

# Method 1: np.polyfit - fits a polynomial (degree 1 = linear)
b1, b0 = np.polyfit(x_values, y_values, 1)
print(f"Method 1 - np.polyfit:")
print(f"  Slope (b1): {b1:.4f}, Intercept (b0): {b0:.4f}\n")

# Method 2: np.linalg.lstsq - least squares solution
A = np.vstack([x_values, np.ones(len(x_values))]).T
result = np.linalg.lstsq(A, y_values, rcond=None)
b1_lstsq, b0_lstsq = result[0]
print(f"Method 2 - np.linalg.lstsq:")
print(f"  Slope (b1): {b1_lstsq:.4f}, Intercept (b0): {b0_lstsq:.4f}\n")

# Method 3: np.corrcoef and statistics (manual but using numpy helpers)
correlation = np.corrcoef(x_values, y_values)[0, 1]
b1_corr = correlation * (np.std(y_values) / np.std(x_values))
b0_corr = np.mean(y_values) - b1_corr * np.mean(x_values)
print(f"Method 3 - Using correlation coefficient:")
print(f"  Slope (b1): {b1_corr:.4f}, Intercept (b0): {b0_corr:.4f}\n")

# Method 4: scipy.stats.linregress (bonus - most comprehensive)
from scipy import stats
slope_scipy, intercept_scipy, r_value, p_value, std_err = stats.linregress(x_values, y_values)
print(f"Method 4 - scipy.stats.linregress:")
print(f"  Slope: {slope_scipy:.4f}, Intercept: {intercept_scipy:.4f}")
print(f"  R-squared: {r_value**2:.4f}, P-value: {p_value:.6f}, Std Error: {std_err:.4f}\n")

# Method 5: sklearn.linear_model.LinearRegression (industry standard for ML)
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score, mean_squared_error

# Reshape x for sklearn (needs 2D array)
X = x_values.reshape(-1, 1)
y = y_values

# Create and fit the model
model = LinearRegression()
model.fit(X, y)

# Get coefficients
b1_sklearn = model.coef_[0]
b0_sklearn = model.intercept_

# Make predictions
y_pred_sklearn = model.predict(X)

# Calculate metrics
r2 = r2_score(y, y_pred_sklearn)
mse = mean_squared_error(y, y_pred_sklearn)
rmse = np.sqrt(mse)

print(f"Method 5 - sklearn.linear_model.LinearRegression:")
print(f"  Slope (coef_): {b1_sklearn:.4f}, Intercept: {b0_sklearn:.4f}")
print(f"  R-squared: {r2:.4f}, MSE: {mse:.4f}, RMSE: {rmse:.4f}\n")

# Predict and plot using sklearn results
y_predicted = y_pred_sklearn

plt.figure(figsize=(10, 6))
plt.scatter(x_values, y_values, color="blue", label="Data points", s=100)
plt.plot(x_values, y_predicted, color="red", linewidth=2, 
         label=f"y = {b0:.2f} + {b1:.2f}x")
plt.xlabel("x", fontsize=12)
plt.ylabel("y", fontsize=12)
plt.title("Linear Regression using NumPy", fontsize=14)
plt.legend()
plt.grid(True, alpha=0.3)
plt.show()
