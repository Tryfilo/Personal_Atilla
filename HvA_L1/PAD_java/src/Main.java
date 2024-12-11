import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttMessage;

public class Main {
    static NAO_crouch crouch;
    static NAO_sit sit;
    static NAO_stand stand;
    static NAO_high_five highFive;
    static NAO_hug hug;
    static String currentCommand = "";

    public static void main(String[] args) throws Exception {
        final String MQTT_SERVER = "***"; // IP and port for MQTT server
        final String MQTT_ID = "***";
        final String ROBOT_IP = "***";

        NAO nao = new NAO();
        crouch = new NAO_crouch(nao);
        sit = new NAO_sit(nao);
        stand = new NAO_stand(nao);
        highFive = new NAO_high_five(nao);
        hug = new NAO_hug(nao);


        MqttClient client = new MqttClient(MQTT_SERVER, MQTT_ID);
        client.connect();

        nao.connect(ROBOT_IP, 9559);


        /*
        Setting up message receiving from MQTT server
         */
        client.setCallback(new MqttCallback() {
            @Override // Method will be called when connection to server is lost, not used at the moment
            public void connectionLost(Throwable throwable) {

            }

            @Override // Method gets called when message is received from server
            public void messageArrived(String s, MqttMessage mqttMessage) throws Exception {
                System.out.println("Message received: " + mqttMessage.toString()); // Write message to console
                handleCommand(mqttMessage.toString()); // Call method that uses message to set the right posture
            }

            @Override
            public void deliveryComplete(IMqttDeliveryToken iMqttDeliveryToken) {

            }
        });
        client.subscribe("device/robot");
    }

    /*
    Method calls other class to move robot and then returns a boolean based on whether an action has been done
     */
    public static boolean handleCommand(String command) throws Exception{
        if (command.matches(currentCommand)) return false; // If the command that got sent is the same as the current state, throw out command
        // Switch statement to set right posture and in some cases change command to return posture
        switch(command) {
            case "Crouch":
                crouch.crouch();
                break;
            case "Sit":
                sit.sit();
                break;
            case "Stand":
                stand.stand();
                break;
            case "HighFive":
                highFive.highFive();
                command = "Stand";
                break;
            case "Hug":
                hug.hug();
                command = "Stand";
                break;
            default:
                return false; // Reached if message doesn't match any commands
        }
        currentCommand = command; // Set command to be ignored in next message
        return true; // Reached if message matched command and thus broke out of switch statement
    }
}


