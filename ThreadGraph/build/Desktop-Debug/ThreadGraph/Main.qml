import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Directed Graph"

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: mainPage
    }

    Component {
        id: mainPage

        Rectangle {
            width: parent.width
            height: parent.height

            Canvas {
                id: graphCanvas
                anchors.fill: parent
                onPaint: {
                    var ctx = getContext("2d")
                    ctx.clearRect(0, 0, width, height)

                    // Define coordinates for vertices
                    var nodes = {
                        1: {x: 100, y: 100},
                        2: {x: 200, y: 100},
                        3: {x: 300, y: 100},
                        4: {x: 100, y: 200},
                        5: {x: 200, y: 200},
                        6: {x: 300, y: 200},
                        7: {x: 100, y: 300},
                        8: {x: 200, y: 300},
                        9: {x: 300, y: 300}
                    }

                    // Define edges with weights
                    var edges = [
                        {start: 1, end: 2, weight: 23},
                        {start: 1, end: 4, weight: 20},
                        {start: 2, end: 3, weight: 24},
                        {start: 2, end: 5, weight: 17},
                        {start: 3, end: 6, weight: 15},
                        {start: 4, end: 2, weight: 22},
                        {start: 4, end: 5, weight: 16},
                        {start: 4, end: 7, weight: 14},
                        {start: 4, end: 8, weight: 18},
                        {start: 5, end: 6, weight: 20},
                        {start: 5, end: 9, weight: 14},
                        {start: 6, end: 9, weight: 13},
                        {start: 7, end: 8, weight: 19},
                        {start: 8, end: 9, weight: 21},
                        {start: 8, end: 4, weight: 25}
                    ]

                    // Draw edges with arrows
                    ctx.lineWidth = 2
                    ctx.strokeStyle = "black"
                    ctx.font = "12px Arial"
                    ctx.textAlign = "center"
                    ctx.textBaseline = "middle"
                    edges.forEach(function(edge) {
                        var start = nodes[edge.start]
                        var end = nodes[edge.end]

                        // Draw line
                        ctx.beginPath()
                        ctx.moveTo(start.x, start.y)
                        ctx.lineTo(end.x, end.y)
                        ctx.stroke()

                        // Calculate direction and draw arrow
                        var angle = Math.atan2(end.y - start.y, end.x - start.x)
                        var arrowLength = 10
                        var arrowAngle = Math.PI / 6  // 30 degrees

                        // Calculate arrowhead points
                        var arrowX1 = end.x - arrowLength * Math.cos(angle - arrowAngle)
                        var arrowY1 = end.y - arrowLength * Math.sin(angle - arrowAngle)
                        var arrowX2 = end.x - arrowLength * Math.cos(angle + arrowAngle)
                        var arrowY2 = end.y - arrowLength * Math.sin(angle + arrowAngle)

                        // Draw arrowhead
                        ctx.beginPath()
                        ctx.moveTo(end.x, end.y)
                        ctx.lineTo(arrowX1, arrowY1)
                        ctx.lineTo(arrowX2, arrowY2)
                        ctx.lineTo(end.x, end.y)
                        ctx.fillStyle = "black"
                        ctx.fill()

                        // Draw weight near the middle of the edge
                        var midX = (start.x + end.x) / 2
                        var midY = (start.y + end.y) / 2
                        ctx.fillText(edge.weight, midX, midY)
                    })

                    // Draw vertices
                    Object.keys(nodes).forEach(function(key) {
                        var node = nodes[key]
                        ctx.beginPath()
                        ctx.arc(node.x, node.y, 15, 0, 2 * Math.PI)
                        ctx.fillStyle = (key === "1") ? "green" : (key === "9") ? "red" : "lightblue"
                        ctx.fill()
                        ctx.strokeStyle = "black"
                        ctx.stroke()

                        // Label each node
                        ctx.fillStyle = "black"
                        ctx.fillText(key, node.x, node.y)
                    })
                }
            }

            Button {
                id: btn
                text: "Рассчитать максимальный поток"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 60
                onClicked: {
                    graphAlgorithm.calculateMaxFlow()
                }
            }

            Text {
                id: txt
                text: "Максимальный поток: " + graphAlgorithm.maxFlow
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: btn.bottom
                anchors.topMargin: 20
                font.pixelSize: 16
            }

            Text {
                text: "Минимальный срез\n" + graphAlgorithm.minCut
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: txt.bottom
                anchors.topMargin: 20
                width: 200
                height: 200
            }

            Button {
                text: "Перейти на другое окно"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                onClicked: stackView.push(secondPage)
            }
        }
    }

    Component {
        id: secondPage

        Rectangle {
            color: "white"

            Column {
                spacing: 20

                Text {
                    text: "Начальная матрица (Минимизация)"
                    font.pixelSize: 20
                }
                ListView {
                    width: 500
                    height: 150
                    model: minimizationAlg.initialMatrix
                    delegate: Row {
                        Repeater {
                            model: modelData
                            Text {
                                text: modelData
                                width: 40
                                height: 20
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                }

                Text {
                    text: "Итоговая матрица (Минимизация)"
                    font.pixelSize: 20
                }
                ListView {
                    width: 500
                    height: 150
                    model: minimizationAlg.resultMatrix
                    delegate: Row {
                        Repeater {
                            model: modelData
                            Text {
                                text: modelData
                                width: 40
                                height: 20
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                }

                Text {
                    text: "Общая стоймость (Минимизация): " + minimizationAlg.totalCost
                    font.pixelSize: 18
                }

                Text {
                    text: "Начальная матрица (Максимизация)"
                    font.pixelSize: 20
                }
                ListView {
                    width: 500
                    height: 150
                    model: maximizationAlg.initialMatrix
                    delegate: Row {
                        Repeater {
                            model: modelData
                            Text {
                                text: modelData
                                width: 40
                                height: 20
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                }

                Text {
                    text: "Итоговая матрица (Максимизация)"
                    font.pixelSize: 20
                }
                ListView {
                    width: 500
                    height: 150
                    model: maximizationAlg.resultMatrix
                    delegate: Row {
                        Repeater {
                            model: modelData
                            Text {
                                text: modelData
                                width: 40
                                height: 20
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                }

                Text {
                    text: "Общая стоймость (Максимизация): " + maximizationAlg.totalCost
                    font.pixelSize: 18
                }
            }
            Button {
                text: "Назад"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                onClicked: stackView.pop()
            }
        }
    }



}
