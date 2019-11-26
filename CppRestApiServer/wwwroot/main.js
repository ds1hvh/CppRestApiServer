var app = new Vue({
    el: "#app",
    data() {
        return {
            size : 2,
            postResult: "",
            getResult: ""
        }
    },
    methods: {
        postButton() {
            const baseURI = 'http://localhost:8080';
            axios.post(baseURI+'/new', { size: this.size })
                .then((result) => {
                    this.postResult="success!";
                })
        },
        getButton(){
            const baseURI = 'http://localhost:8080';
            axios.get(baseURI+'/game', { size: this.size })
                .then((result) => {
                    console.log(result.data);
                    this.getResult = result.data;
                })
        }
    }
})