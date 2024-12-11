from flask import Flask, render_template
from LDR import TopLeftSensor, TopCenterSensor, TopRightSensor, MiddleLeftSensor, MiddleCenterSensor, \
    MiddleRightSensor, BottomLeftSensor, BottomCenterSensor, BottomRightSensor

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html", TopLeft=TopLeftSensor, TopCenter=TopCenterSensor, TopRight=TopRightSensor,
                           MiddleLeft=MiddleLeftSensor, MiddleCenter=MiddleCenterSensor, MiddleRight=MiddleRightSensor,
                           BottomLeft=BottomLeftSensor, BottomCenter=BottomCenterSensor, BottomRight=BottomRightSensor)


if __name__ == "__main__":
    app.run(debug=True, port=80, host='0.0.0.0')
