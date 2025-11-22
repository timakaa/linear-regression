import matplotlib.pyplot as plt
import math

data = [{ "x": 1, "y": 1.5 }, { "x": 2, "y": 3.8 }, { "x": 3, "y": 6.7 }, { "x": 4, "y": 9.0 }, { "x": 5, "y": 11.2 }, { "x": 6, "y": 13.6 }, { "x": 7, "y": 16 }]

class LinearRegression():
    def __init__(self, data):
        self.data = data

    def _xy_product(self):
        result = []
        for cord in self.data:
            result.append(cord["x"] * cord["y"])
        return result

    def _x_squared(self):
        result = []
        for coord in self.data:
            result.append(coord["x"] ** 2)
        return result

    def _x_sum(self):
        result = 0
        for coord in self.data:
            result += coord["x"]
        return result

    def _y_sum(self):
        result = 0
        for coord in self.data:
            result += coord["y"]
        return result

    def _xy_sum(self):
        xy_prod = self._xy_product()
        return sum(xy_prod)

    def _x_squared_sum(self):
        x_2 = self._x_squared()
        return sum(x_2)

    def _mean(self, data):
        return sum(data) / len(data)

    def _std(self, data):
        result = 0
        mean = self._mean(data)
        for num in data:
            result += (num - mean)**2

        return math.sqrt(result / (len(data)))

    # y = b0 + b1 * x
    # get b1
    def _get_slope(self):
        count = len(self.data)
        # Formula
        result = (count * self._xy_sum() - self._x_sum() * self._y_sum()) / (count * self._x_squared_sum() - self._x_sum() ** 2)
        return result

    # get b0
    def _get_intersept(self):
        count = len(data)
        # Formula
        result = (self._y_sum() - self._get_slope() * self._x_sum()) / count
        return result

    def _corr(self):
        result = 0
        x_mean = self._mean([point["x"] for point in self.data])
        y_mean = self._mean([point["y"] for point in self.data])
        x_std = self._std([point["x"] for point in self.data])
        y_std = self._std([point["y"] for point in self.data])

        for point in self.data:
            result += ((point["x"] - x_mean) / x_std) * ((point["y"] - y_mean) / y_std)

        return result / len(self.data)

    def get_y_predicted(self, b0, b1, x_values):
        return [b0 + b1 * x for x in x_values]

    def leastsq(self):
        b0 = self._get_intersept()
        b1 = self._get_slope()

        x_values = [point["x"] for point in self.data]
        y_values = [point["y"] for point in self.data]

        return b0, b1, self.get_y_predicted(b0, b1, x_values), x_values, y_values
    
    def correlcoef(self):
        x_values = [point["x"] for point in self.data]
        y_values = [point["y"] for point in self.data]
        corr = self._corr()

        b1 = corr * (self._std(y_values) / self._std(x_values))
        b0 = self._mean(y_values) - b1 * self._mean(x_values)

        return b0, b1, self.get_y_predicted(b0, b1, x_values), x_values, y_values 

polyfit = LinearRegression(data)
# b0, b1, y_predicted, x_values, y_values = polyfit.leastsq()
b0, b1, y_predicted, x_values, y_values = polyfit.correlcoef()

plt.figure(figsize=(10, 6))
plt.scatter(x_values, y_values, color="blue")
plt.plot(x_values, y_predicted, color="red")
plt.show()
