public class NAO_sit {
    private NAO nao;

    public NAO_sit(NAO nao) {
        this.nao = nao;
    }

    // this method is used to let the NAO sit
    public void sit() throws Exception {
        System.out.println("Is going to sit");
        nao.speak("Ik  ga  zitten");
        nao.postureSetUp("Sit");
    }
}
