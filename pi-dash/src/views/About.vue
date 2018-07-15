<template>
    <div class="about">
        <h1>This is an about page</h1>
    </div>
</template>

<script>
export default {
    created() {
        const postData = {
            client_id: 2,
            client_secret:  'ShszeLwsH0LJUuCzKa49YzeO7rvtGe4S8DcOwMFL',
            grant_type:     'password',
            username:       'walz.samuel@gmail.com',
            password:       'secret',
            scope:          '*',
        };
        this.$http.post('http://192.168.0.199:8000/oauth/token', postData)
            .then(response => {
                console.log(response);
                const header = {
                    'Accept': 'application/json',
                    'Authorization': 'Bearer ' + response.body.access_token
                };
                this.$http.get('http://192.168.0.199:8000/api/user', {headers: header})
                    .then(response => {
                        console.log(response);
                    }).catch(function(e) {
                        console.log(e); // "oh, no!"
                    });
            }).catch(function(e) {
                console.log(e); // "oh, no!"
            });
    },
};
</script>
